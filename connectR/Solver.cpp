// Copyright 2017 Timothy Oltjenbruns.

#include <Utils.hpp>
#include <random>
#include "Solver.hpp"

using cr::Board;
using cr::Tree;
using cr::Solver;

Solver::~Solver() {
  delete tree;
}

Solver::Solver(Board* start, bool player)
    : start(start), tree(new Tree(start)), player(player) { }

Board::size_type Solver::solve() {
  miniMax(tree, populate, evaluate, propagate);
  const Tree* node(tree);
  while (node->getChildren().size() != 0) {
    node = node->getChildren().at(stochasticSelectBest(node));
    std::cout << *node->getData() << std::endl;
  }
  return stochasticSelectBest(tree);
}

void Solver::populate(Tree *node, Board::size_type depth) {
  if (depth > 6) return;
  auto width(node->getData()->getWidth());
  for (Board::size_type column(0); column < width; ++column) {
    Board board(node->getData());
    board.drop(column);
    node->getChildren().push_back(new Tree(node, &board));
  }
}

void Solver::evaluate(Tree *node, Board::size_type depth) {
  node->setHeuristic(node->getData()->score());
}

void Solver::propagate(Tree *node, Board::size_type depth) {
  auto compare = [](auto &a, auto &b){
    return a->getHeuristic() < b->getHeuristic();
  };
  if (depth % 2 == 0)
    node->setHeuristic((*std::max_element(node->getChildren().begin(), node->getChildren().end(), compare))->getHeuristic());
  else
    node->setHeuristic((*std::min_element(node->getChildren().begin(), node->getChildren().end(), compare))->getHeuristic());
  // clean up unused children
  std::replace_if(
      node->getChildren().begin(), node->getChildren().end(),
      [node](Tree *a) {
        if (a->getHeuristic() == node->getHeuristic())
          return false;
        delete a;
        return true;
      },
      nullptr);
}

Board::size_type Solver::stochasticSelectBest(const Tree *node) {
  std::vector<Board::size_type> matches;
  for (Board::size_type column(0); column < node->getChildren().size(); ++column)
    if (node->getChildren().at(column) != nullptr &&
        node->getChildren().at(column)->getHeuristic() == node->getHeuristic())
      matches.push_back(column);
  return matches[rand() % matches.size()];
}