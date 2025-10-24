#include "ChessBoard.h"
#include "ChessBoardPrint.h"
#include <memory>

int main() {
  ChessBoard board;
  ChessBoardPrint printer(board);

  // Sett opp brikker
  board.squares[4][0] = std::make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = std::make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  printer.print_board(board);

  std::cout << "\nInvalid moves:\n";
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");

  std::cout << "\nA simulated game:\n";
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}