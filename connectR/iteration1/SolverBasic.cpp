// Copyright 2017 Timothy Oltjenbruns.

#include <Utils.hpp>
#include "SolverBasic.hpp"

using cr::iteration1::SolverBasic;

short SolverBasic::solve() {
  miniMax(&tree, populate, evaluate);
  return 0;
}

void SolverBasic::populate(tree_type *node, tree_type::data_type::size_type depth) {
  if (depth > 3) return;
  unsigned long width((unsigned long) node->getSize());
  std::vector<tree_type> children(width);
  for (auto column(0); column < width; ++column) {
    children[column] = TreeBasic(Board2D(node->getData()));
    children[column].getData().drop(column, depth % 2 == 0);
  }
}

void SolverBasic::evaluate(tree_type *node, tree_type::data_type::size_type depth) {

}
