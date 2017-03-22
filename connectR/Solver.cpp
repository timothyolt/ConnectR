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

Solver::Solver(Board* start)
    : start(start), tree(new Tree(start)) { }

Board::size_type Solver::solve() {
  miniMax(tree, populate, evaluate, propagate);
  // store a best value
  auto best(stochasticSelectBest(tree));
  // print an ideal target
  const Tree* node((*tree)[best]);
  while (!node->empty())
    node = (*node)[stochasticSelectBest(node)];
  std::cout << "Ideal board with slot " << best << ": " << std::endl << *node->getData() << std::endl;
  // return previous selected best
  return best;
}

void Solver::populate(Tree *node, Board::size_type depth) {
  if (depth > 6) return;
  auto width(node->getData()->getWidth());
  for (Board::size_type column(0); column < width; ++column) {
    Board board(node->getData());
    board.drop(column);
    node->set(column, board.isLegal() ? new Tree(node, &board) : nullptr);
  }
}

void Solver::evaluate(Tree *node, Board::size_type player) {
  node->setHeuristic(node->getData()->score(player));
}

void Solver::propagate(Tree *node, Board::size_type player) {
  node->setHeuristic(
      (*std::min_element(
          node->begin(), node->end(), player
              ? ([](Tree *&a, Tree *&b) {
                  if (a == nullptr)
                    return false;
                  if (b == nullptr)
                    return true;
                  return a->getHeuristic() < b->getHeuristic();
                })
              : ([](Tree *&a, Tree *&b) {
                  if (a == nullptr)
                    return true;
                  if (b == nullptr)
                    return false;
                  return a->getHeuristic() > b->getHeuristic();
                })))
          ->getHeuristic());
  // clean up unused children
//  std::replace_if(
//      node->getChildren().begin(), node->getChildren().end(),
//      [node](Tree *a) {
//        if (a->getHeuristic() == node->getHeuristic())
//          return false;
//        delete a;
//        return true;
//      },
//      nullptr);
}

Board::size_type Solver::stochasticSelectBest(const Tree *node) {
  std::vector<Board::size_type> matches;
  for (Board::size_type column(0); column < node->size; ++column)
    if ((*node)[column] != nullptr &&
        (*node)[column]->getHeuristic() == node->getHeuristic())
      matches.push_back(column);
  return matches[rand() % matches.size()];
}
