// Copyright 2017 Tim Oltjenbruns.

#include <iostream>
#include "iteration1/Board2D.hpp"

using cr::interface::IBoard;
using cr::interface::BoardSize;
using cr::iteration1::Board2D;
using size_type = cr::iteration1::Board2D::size_type;
using data_type = cr::iteration1::Board2D::data_type;

Board2D::Board2D() : IBoard(), board({ }) { }

Board2D::Board2D(BoardSize<size_type> size)
    : IBoard(size), board({ }) {
  for (auto column(0); column < size.getWidth(); ++column)
    board.push_back({ });
}

Board2D::Board2D(const Board2D* origin)
    : IBoard(*origin), board(origin->board) { }

const data_type Board2D::get(size_type column, size_type row) const {
  return board[column][row];
}

void Board2D::drop(const size_type column, const data_type state) {
  std::cout << "dropped " << state << " into " << column << std::endl;
  if (board[column].size() >= getSize().getHeight()) return;
  board[column].push_back(state);
}