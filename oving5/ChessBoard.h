#pragma once
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  std::function<void(const std::string &, const std::string &, const std::string &, const std::string &)> on_move; // Color, type, from, to
  std::function<void(const std::string &, const std::string &, const std::string &, const std::string &)> on_illegal_move;
  std::function<void(const std::string &, const std::string &)> on_no_piece;                                          // Color, coordinates
  std::function<void(const std::string &, const std::string &, const std::string &, const std::string &)> on_capture; // Color, type, target type and coordinates
  std::function<void(Color)> on_lose;
  std::function<void(const ChessBoard &)> after_move;

  class Piece {
  public:
    Piece(Color color);
    virtual ~Piece();

    Color color;
    std::string color_string() const;

    virtual std::string type() const = 0;
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    virtual std::string symbol() const = 0;
  };

  class King : public Piece {
  public:
    King(Color color);
    std::string type() const override;
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
    std::string symbol() const override;
  };

  class Knight : public Piece {
  public:
    Knight(Color color);
    std::string type() const override;
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
    std::string symbol() const override;
  };

  ChessBoard();

  bool move_piece(const std::string &from, const std::string &to);

  std::vector<std::vector<std::unique_ptr<Piece>>> squares;
};
