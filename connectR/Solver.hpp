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
  Tree* tree;
  bool player;
  static void populate(Tree* node, Board::size_type depth);
  static void evaluate(Tree* node, Board::size_type depth);
  static void propagate(Tree* node, Board::size_type depth);
  static typename Board::size_type stochasticSelectBest(const Tree* node);
 public:
  ~Solver();
  Solver(Board* start, bool player);
  typename Board::size_type solve();
};

}  // namespace cr

#endif  // CONNECTR_SOLVERBASIC_HPP_
