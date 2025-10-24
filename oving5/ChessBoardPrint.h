#pragma once
#include "ChessBoard.h"

class ChessBoardPrint {
public:
  explicit ChessBoardPrint(ChessBoard &board);
  void print_board(const ChessBoard &chessBoard) const;

private:
  ChessBoard &board;
};
