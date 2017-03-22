// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_TREEBASIC_HPP_
#define CONNECTR_TREEBASIC_HPP_

#include "Board.hpp"

namespace cr {

class Tree {
 private:
  const Tree* parent;
  const Board board;

 public:
  const Board::size_type size;

 private:
  Tree** children;
  Board::score_type heuristic;

 public:
  ~Tree();

  Tree();

  explicit Tree(const Board* board);

  Tree(const Tree* parent, const Board* board);

  const Tree *getParent() const;

  const Board* getData() const;

  void set(Board::size_type index, Tree* child);

  Tree* operator[](Board::size_type index);

  const Tree* operator[](Board::size_type index) const;

  Tree** begin();

  Tree** end();

  Tree *const * begin() const;

  Tree *const * end() const;

  const bool empty() const;

  Board::score_type getHeuristic() const;

  void setHeuristic(Board::score_type heuristic);
};

}  // namespace cr

#endif  // CONNECTR_TREEBASIC_HPP_
