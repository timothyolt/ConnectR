// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_TREEBASIC_HPP_
#define CONNECTR_TREEBASIC_HPP_

#include "Board.hpp"

namespace cr {

class Tree {
 private:
  const Tree* parent;
  const Board board;
  std::vector<Tree*> children;
  Board::score_type heuristic;

 public:

  ~Tree();

  Tree();

  explicit Tree(const Board* data);

  Tree(const Tree* parent, const Board* board);

  Tree(const Board* data, const std::vector<Tree*> &children);

  Tree(const Tree* parent, const Board& data, const std::vector<Tree*>& children);

  const Tree *getParent() const;

  const Board* getData() const;

  Tree* operator[](long index);

  const Tree* operator[](long index) const;

  const std::vector<Tree*>& getChildren() const;

  std::vector<Tree*>& getChildren();

  Board::score_type getHeuristic() const;

  void setHeuristic(Board::score_type heuristic);
};

}  // namespace cr

#endif  // CONNECTR_TREEBASIC_HPP_
