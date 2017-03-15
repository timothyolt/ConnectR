// Copyright 2017 Timothy Oltjenbruns.

#include <assert.h>
#include "Tree.hpp"

using std::vector;
using cr::Board;
using cr::Tree;

Tree::~Tree() {
  for (auto c(0); c < children.size(); ++c)
    delete children[c];
}

Tree::Tree()
    : parent(nullptr), data(), children({ }) { }

Tree::Tree(Board data)
    : parent(nullptr), data(data), children({ }) { }

Tree::Tree(Tree *parent, Board data)
    : parent(parent), data(data), children({ }) { }

Tree::Tree(Board data, vector<Tree*> &children)
    : parent(nullptr), data(data), children(children) {
  assert(children.size() == 0 || children.size() == data.getWidth());
}

Tree::Tree(Tree *parent, Board data, vector<Tree*>& children)
    : parent(parent), data(data), children(children) {
  assert(children.size() == 0 || children.size() == data.getWidth());
}

const Board::size_type Tree::getSize() const {
  return (const Board::size_type) children.size();
}

const Tree *Tree::getParent() const {
  return parent;
}

Tree *Tree::getParent() {
  return parent;
}

void Tree::setParent(Tree *parent) {
  Tree::parent = parent;
}

const Board& Tree::getData() const {
  return data;
}

Board& Tree::getData() {
  return data;
}

Tree* Tree::operator[](long index) {
  return children[index];
}

const Tree* Tree::operator[](long index) const {
  return children[index];
}

void Tree::setData(Board data) {
  Tree::data = data;
}

const vector<Tree*>& Tree::getChildren() const {
  return children;
}

vector<Tree*>& Tree::getChildren() {
  return children;
}

void Tree::setChildren(const vector<Tree*>& children) {
  Tree::children = children;
}

int Tree::getHeuristic() const {
  return heuristic;
}

void Tree::setHeuristic(int heuristic) {
  Tree::heuristic = heuristic;
}
