// Copyright 2017 Tim Oltjenbruns.

#include <iostream>
#include "Board.hpp"

using cr::Board;
using size_type = Board::size_type;
using data_type = Board::data_type;

Board::Board()
    : width(0), height(0), connect(0), board({ }) { }

Board::Board(size_type width, size_type height, size_type connect)
    : width(width), height(height), connect(connect), board({ }) {
  for (auto column(0); column < width; ++column)
    board.push_back({ });
}

Board::Board(const Board* origin)
    : width(origin->width), height(origin->height), connect(origin->connect), board(origin->board) { }

size_type Board::getWidth() const {
  return width;
}

size_type Board::getHeight() const {
  return height;
}

size_type Board::getConnect() const {
  return connect;
}

const data_type Board::get(size_type column, size_type row) const {
  return board[column][row];
}

void Board::drop(const size_type column, const data_type state) {
  if (board[column].size() >= height) return;
  board[column].push_back(state);
}

std::ostream &cr::operator<<(std::ostream &os, const Board &d) {
  using std::cout;
  using std::endl;
  cout << '+';
  for (auto column(0); column < d.width; ++column)
    cout << '-';
  cout << '+' << endl;
  for (auto row(d.height); row >= 0; --row) {
    cout << '|';
    for (auto column(0); column < d.width; ++column)
      if (row < d.board[column].size())
        cout << (d.board[column][row] == 0 ? 'X' : 'O');
      else
        cout << ' ';
    cout << '|' << endl;
  }
  cout << '+';
  for (auto column(0); column < d.width; ++column)
    cout << '-';
  cout << '+' << endl;
  return os;
}
