// Copyright 2017 Tim Oltjenbruns.

#include <iostream>
#include <sstream>
#include "Board.hpp"
#include "Utils.hpp"

using cr::Board;
using size_type = Board::size_type;
using score_type = Board::score_type;
using bitset = boost::dynamic_bitset<>;

bitset::size_type Board::shiftCount(bitset::size_type shift) const {
  size_type score(0);
  auto copy(board[0]);
  for (auto i(0); copy.any(); ++i) {
    copy &= copy << shift;
    score += copy.count() << (i * 4);
  }
  copy = board[1];
  for (auto i(0); copy.any(); ++i) {
    copy &= copy << shift;
    score -= copy.count() << (i * 4);
  }
  return score;
}

Board::~Board() {
  if (columnHeight != nullptr)
    delete[] columnHeight;
  if (history != nullptr)
    delete[] history;
}

Board::Board()
    : width(0), height(0), connect(0), area(0)  // , board({ })
    , board(), cushion(0)
    , count(0), columnHeight(nullptr), history(nullptr) { }

Board::Board(size_type width, size_type height, size_type connect)
    : width(width), height(height), connect(connect), area(width * (height + 1))  // , board({ })
    , board({bitset(area), bitset(area)}), cushion(area)
    , count(0), columnHeight(new size_type[width]), history(new size_type[width * height]) {
  // set mask for cushion (top) row
  for (size_type i(height); i < cushion.size(); i += height + 1)
    cushion.set(i);
  // set initial column indices
  for (auto column(0); column < width; ++column)
    columnHeight[column] = (height + 1) * column;
}

Board::Board(const Board* origin)
    : width(origin->width), height(origin->height), connect(origin->connect), area(origin->area)
    , board({origin->board[0], origin->board[1]}), cushion(origin->cushion)
    , count(origin->count), columnHeight(new size_type[width]), history(new size_type[width * height]) {
  std::copy(origin->columnHeight, origin->columnHeight + (width), columnHeight);
  std::copy(origin->history, origin->history + ((width * height)), history);
}

size_type Board::getWidth() const {
  return width;
}

size_type Board::getHeight() const {
  return height;
}

size_type Board::getConnect() const {
  return connect;
}

static bool access(bitset* from, unsigned long i) {
  return from->operator[](i);
}

void Board::drop(const size_type column) {
  bitset move(area);
  move[columnHeight[column]] = true;
  // prevent column overflow
  if ((move & cushion).any()) return;
  board[count & 1] |= move;
  history[count++] = column;
  columnHeight[column] += 1;
  return;
}

void Board::undo() {
  auto column(--columnHeight[--count]);
  bitset move(area, 1);
  move <<= columnHeight[column];
  board[count & 1] ^= move;
}

score_type Board::score() const {
  score_type score(0);
  score += shiftCount(1);
  score += shiftCount(height);
  score += shiftCount(height + 1);
  score += shiftCount(height + 2);
  //std::cout << this->toString() << score << std::endl;
  return score;
}

std::string Board::toString() const {
  std::stringstream stream;
  stream << *this;
  return stream.str();
}

size_type Board::getCount() const {
  return count;
}

std::ostream &cr::operator<<(std::ostream &os, const Board &d) {
  using std::endl;
  os << '+';
  for (auto column(0); column < d.width; ++column)
    os << '-';
  os << '+' << endl;
  for (long long row((long long) (d.height - 1)); row >= 0; --row) {
    os << '|';
    for (auto column(row); column < d.area; column += d.height + 1) {
      auto a(d.board[0][column]);
      auto b(d.board[1][column]);
      os << (a ? 'X' :
             b ? '0' : '~');
    }
    os << '|' << endl;
  }
  os << '+';
  for (auto column(0); column < d.width; ++column)
    os << '-';
  os << '+' << endl;
  return os;
}
