#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <sstream>

using boost::asio::ip::tcp;

class HttpServer {
  struct Connection {
    tcp::socket socket;
    explicit Connection(boost::asio::io_context& io) : socket(io) {}
  };

  boost::asio::io_context io_;
  tcp::endpoint endpoint_;
  tcp::acceptor acceptor_;

  static std::string build_response(int status, const std::string& text) {
    std::string status_text = (status == 200) ? "OK" : "Not Found";
    std::ostringstream oss;
    oss << "HTTP/1.1 " << status << ' ' << status_text << "\r\n"
        << "Content-Type: text/plain; charset=utf-8\r\n"
        << "Content-Length: " << text.size() << "\r\n"
        << "Connection: close\r\n"
        << "\r\n"
        << text;
    return oss.str();
  }

  void handle_request(std::shared_ptr<Connection> conn) {
    auto buf = std::make_shared<boost::asio::streambuf>();

    boost::asio::async_read_until(
        conn->socket, *buf, "\r\n",
        [this, conn, buf](const boost::system::error_code& ec, std::size_t) {
          if (ec) return;

          std::istream is(buf.get());
          std::string first_line;
          std::getline(is, first_line);
          if (!first_line.empty() && first_line.back() == '\r')
            first_line.pop_back();

          if (first_line.find("HTTP/") != std::string::npos) {

            std::string method, target, version;
            std::istringstream rl(first_line);
            rl >> method >> target >> version;


            boost::asio::async_read_until(
                conn->socket, *buf, "\r\n\r\n",
                [this, conn, buf, method, target](const boost::system::error_code& ec2, std::size_t) {
                  if (ec2) return;

                  int status = 404;
                  std::string body = "404 Not Found\n";

                  if (method == "GET") {
                    if (target == "/") {
                      status = 200; body = "Dette er hovedsiden\n";
                    } else if (target == "/en_side") {
                      status = 200; body = "Dette er en side\n";
                    }
                  }

                  auto response = std::make_shared<std::string>(
                      build_response(status, body));

                  boost::asio::async_write(
                      conn->socket, boost::asio::buffer(*response),
                      [conn, response](const boost::system::error_code&, std::size_t) {
                        boost::system::error_code ignored;
                        conn->socket.shutdown(tcp::socket::shutdown_both, ignored);
                        conn->socket.close(ignored);
                      });
                });

          } else {

            auto out = std::make_shared<std::string>(first_line + "\r\n");
            boost::asio::async_write(
                conn->socket, boost::asio::buffer(*out),
                [this, conn, out](const boost::system::error_code& ec3, std::size_t) {
                  if (!ec3) {

                    handle_request(conn);
                  }
                });
          }
        });
  }


  void accept_loop() {
    auto conn = std::make_shared<Connection>(io_);
    acceptor_.async_accept(
        conn->socket,
        [this, conn](const boost::system::error_code& ec) {
          // Start å lytte etter neste connection uansett
          accept_loop();
          if (!ec) handle_request(conn);
        });
  }

public:
  HttpServer() : endpoint_(tcp::v4(), 8080), acceptor_(io_, endpoint_) {}
  void start() { accept_loop(); io_.run(); }
};

int main() {
  std::cout << "Starter HTTP-server på http://localhost:8080" << std::endl;
  HttpServer server;
  server.start();
}
