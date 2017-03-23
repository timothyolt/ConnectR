// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_SOLVERBASIC_HPP_
#define CONNECTR_SOLVERBASIC_HPP_

#include "Board.hpp"
#include "Tree.hpp"

namespace cr {

class Solver {
 public:
 private:
  const Board start;
  const Board::size_type maxDepth;
  Tree* tree;
  static void populate(Tree* node, Board::size_type depth);
  static void evaluate(Tree* node, Board::size_type player);
  static void propagate(Tree* node, Board::size_type player);
  static typename Board::size_type stochasticSelectBest(const Tree* node);
 public:
  ~Solver();
  Solver(Board* start, Board::size_type maxDepth);
  typename Board::size_type solve();
};

}  // namespace cr

#endif  // CONNECTR_SOLVERBASIC_HPP_
