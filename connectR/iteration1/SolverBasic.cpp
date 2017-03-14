// Copyright 2017 Timothy Oltjenbruns.

#include <Utils.hpp>
#include <random>
#include <algorithm>
#include "SolverBasic.hpp"

using cr::iteration1::SolverBasic;

SolverBasic::SolverBasic(cr::iteration1::Board2D start, bool player) : ISolver(start, player) { }

short SolverBasic::solve() {
  miniMax(&tree, populate, evaluate, propagate);
  std::vector<short> matches;
  for (short column(0); column < tree.getChildren().size(); ++column)
    if (tree[column].getHeuristic() == tree.getHeuristic())
      matches.push_back(column);
  return matches[rand() & matches.size()];
}

void SolverBasic::populate(tree_type *node, tree_type::data_type::size_type depth) {
  if (depth > 3) return;
  unsigned long width((unsigned long) node->getData().getSize().getWidth());
  std::vector<tree_type> children;
  for (auto column(0); column < width; ++column) {
    children.emplace_back(node, Board2D(node->getData()));
    children[column].getData().drop((const short) column, depth % 2 == 0);
  }
  node->setChildren(children);
}

void SolverBasic::evaluate(tree_type *node, tree_type::data_type::size_type depth) {
  node->setHeuristic(rand() % 42);
}

void SolverBasic::propagate(tree_type *node, tree_type::data_type::size_type depth) {
  auto compare = [](auto &a, auto &b){
    return a.getHeuristic() < b.getHeuristic();
  };
  if (depth % 2 == 0)
    node->setHeuristic(std::max_element(node->getChildren().begin(), node->getChildren().end(), compare)->getHeuristic());
  else
    node->setHeuristic(std::min_element(node->getChildren().begin(), node->getChildren().end(), compare)->getHeuristic());
  // TODO(timothyolt): clean up unused children
}
