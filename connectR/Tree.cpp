// Copyright 2017 Timothy Oltjenbruns.

#include "Tree.hpp"

using std::vector;
using cr::Board;
using cr::Tree;

Tree::~Tree() {
  for (auto c(0); c < children.size(); ++c)
    delete children[c];
}

Tree::Tree()
    : parent(nullptr), board(), children({ }) { }

Tree::Tree(const Board* data)
    : parent(nullptr), board(data), children({ }) { }

Tree::Tree(const Tree *parent, const Board* board)
    : parent(parent), board(board), children({ }) { }

Tree::Tree(const Board* data, const vector<Tree*> &children)
    : parent(nullptr), board(data), children(children) {
  assert(children.size() == 0 || children.size() == data->getWidth());
}

Tree::Tree(const Tree *parent, const Board& data, const vector<Tree*>& children)
    : parent(parent), board(data), children(children) {
  assert(children.size() == 0 || children.size() == data.getWidth());
}

const Tree *Tree::getParent() const {
  return parent;
}

const Board* Tree::getData() const {
  return &board;
}

Tree* Tree::operator[](long index) {
  return children[index];
}

const Tree* Tree::operator[](long index) const {
  return children[index];
}

const vector<Tree*>& Tree::getChildren() const {
  return children;
}

vector<Tree*>& Tree::getChildren() {
  return children;
}

Board::score_type Tree::getHeuristic() const {
  return heuristic;
}

void Tree::setHeuristic(Board::score_type heuristic) {
  Tree::heuristic = heuristic;
}
