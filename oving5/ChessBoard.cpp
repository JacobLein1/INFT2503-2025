#include "ChessBoard.h"
#include <cmath>
#include <iomanip>

using namespace std;

// ---------------- Piece ----------------
ChessBoard::Piece::Piece(Color color) : color(color) {}
ChessBoard::Piece::~Piece() {}

std::string ChessBoard::Piece::color_string() const {
  return color == Color::WHITE ? "white" : "black";
}

// ---------------- King ----------------
ChessBoard::King::King(Color color) : Piece(color) {}

std::string ChessBoard::King::type() const { return "King"; }

bool ChessBoard::King::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dx = abs(to_x - from_x);
  int dy = abs(to_y - from_y);
  return (dx <= 1 && dy <= 1 && !(dx == 0 && dy == 0));
}

std::string ChessBoard::King::symbol() const {
  return (color == Color::WHITE) ? "WKI" : "BKI";
}

// ---------------- Knight ----------------
ChessBoard::Knight::Knight(Color color) : Piece(color) {}

std::string ChessBoard::Knight::type() const { return "Knight"; }

bool ChessBoard::Knight::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dx = abs(to_x - from_x);
  int dy = abs(to_y - from_y);
  return ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) && !(dx == 0 && dy == 0);
}

std::string ChessBoard::Knight::symbol() const {
  return (color == Color::WHITE) ? "WKN" : "BKN";
}

// ---------------- ChessBoard ----------------
ChessBoard::ChessBoard() {
  squares.resize(8);
  for (auto &col : squares)
    col.resize(8);
}

bool ChessBoard::move_piece(const std::string &from, const std::string &to) {
  int from_x = from[0] - 'a';
  int from_y = stoi(string() + from[1]) - 1;
  int to_x = to[0] - 'a';
  int to_y = stoi(string() + to[1]) - 1;

  auto &piece_from = squares[from_x][from_y];
  if (!piece_from) {
    if (on_no_piece)
      on_no_piece(from, to);
    return false;
  }

  if (!piece_from->valid_move(from_x, from_y, to_x, to_y)) {
    if (on_illegal_move)
      on_illegal_move(piece_from->color_string(), piece_from->type(), from, to);
    return false;
  }

  if (on_move)
    on_move(piece_from->color_string(), piece_from->type(), from, to);

  auto &piece_to = squares[to_x][to_y];
  if (piece_to) {
    if (piece_from->color != piece_to->color) {
      on_capture(piece_from->color_string(), piece_from->type(), piece_to->type(), to);
      if (auto king = dynamic_cast<King *>(piece_to.get())) {
        if (on_lose) {
          on_lose(king->color);
        }
      }
    } else {
      if (on_illegal_move) {
        on_illegal_move(piece_from->color_string(), piece_from->type(), from, to);
        return false;
      }
    }
  }

  piece_to = std::move(piece_from);
  if (after_move)
    after_move(*this);
  // cout << "\n";
  // printBoard(*this);
  // cout << "\n";
  return true;
}
