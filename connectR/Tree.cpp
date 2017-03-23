// Copyright 2017 Timothy Oltjenbruns.

#include "Tree.hpp"

using std::vector;
using cr::Board;
using cr::Tree;

Tree::~Tree() {
  for (auto c(0); c < size; ++c)
    delete children[c];
  delete[] children;
}

Tree::Tree()
    : parent(nullptr), board(), size(0), children(nullptr) { }

Tree::Tree(const Board* board)
    : parent(nullptr), board(board), size(board->getWidth()), children(new Tree*[size]) {
  for (auto child(0); child < size; ++child)
    children[child] = nullptr;
}

Tree::Tree(const Tree *parent, const Board* board)
    : parent(parent), board(board), size(board->getWidth()), children(new Tree*[size]) {
  for (auto child(0); child < size; ++child)
    children[child] = nullptr;
}

const Tree *Tree::getParent() const {
  return parent;
}

const Board* Tree::getData() const {
  return &board;
}

void Tree::set(Board::size_type index, Tree* child) {
  children[index] = child;
}

Tree* Tree::operator[](Board::size_type index) {
  return children[index];
}

const Tree* Tree::operator[](Board::size_type index) const {
  return children[index];
}

Tree **Tree::begin() {
  return children;
}

Tree **Tree::end() {
  return children + size;
}

Tree *const * Tree::begin() const {
  return children;
}

Tree *const * Tree::end() const {
  return children + size;
}

const bool Tree::empty() const {
  return std::all_of(begin(), end(), [](Tree *const & c){ return c == nullptr; });
}

Board::score_type Tree::getHeuristic() const {
  return heuristic;
}

void Tree::setHeuristic(Board::score_type heuristic) {
  Tree::heuristic = heuristic;
}
