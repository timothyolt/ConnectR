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
  int heuristic;

 public:

  ~Tree();

  Tree();

  explicit Tree(Board data);

  Tree(Tree* parent, Board board);

  Tree(Board data, std::vector<Tree*> &children);

  Tree(Tree* parent, Board data, std::vector<Tree*>& children);

  const Tree *getParent() const;

  const Board& getData() const;

  Tree* operator[](long index);

  const Tree* operator[](long index) const;

  const std::vector<Tree*>& getChildren() const;

  std::vector<Tree*>& getChildren();

  int getHeuristic() const;

  void setHeuristic(int heuristic);
};

}  // namespace cr

#endif  // CONNECTR_TREEBASIC_HPP_
