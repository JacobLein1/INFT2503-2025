#include "ChessBoardPrint.h"
#include <iomanip>
#include <iostream>

using std::cout;
using std::setw;
using std::string;

ChessBoardPrint::ChessBoardPrint(ChessBoard &board) : board(board) {
  using Color = ChessBoard::Color;

  // Move
  board.on_move = [](const string &color, const string &type,
                     const string &from, const string &to) {
    cout << color << " " << type << " is moving from "
         << from << " to " << to << "\n";
  };

  // Illegal move is tried
  board.on_illegal_move = [](const string &color, const string &type,
                             const string &from, const string &to) {
    cout << "can not move " << color << " " << type
         << " from " << from << " to " << to << "\n";
  };

  // No piece in from coordinates
  board.on_no_piece = [](const string &from, const string & /*to*/) {
    cout << "no piece at " << from << "\n";
  };

  // Piece captured
  board.on_capture = [](const string &mover_color, const string &mover_type,
                        const string &captured_type, const string &at) {
    cout << mover_color << " " << mover_type
         << " captured " << captured_type << " at " << at << "\n";
  };

  // Player loses
  board.on_lose = [](Color loser) {
    cout << (loser == Color::WHITE ? "white" : "black") << " lost the game\n";
  };

  // After every move the board is printed
  board.after_move = [this](const ChessBoard &b) {
    cout << "\n";
    this->print_board(b);
    cout << "\n";
  };
}

// Function for printing the board
void ChessBoardPrint::print_board(const ChessBoard &chessBoard) const {
  cout << "     a   b   c   d   e   f   g   h\n";
  for (int y = 7; y >= 0; --y) {
    cout << (y + 1) << " ";
    for (int x = 0; x < 8; ++x) {
      const auto &piece = chessBoard.squares[x][y];
      string cell = piece ? piece->symbol() : ".";
      cout << setw(4) << cell;
    }
    cout << "\n";
  }
}
