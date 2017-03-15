// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_TREEBASIC_HPP_
#define CONNECTR_TREEBASIC_HPP_

#include "Board.hpp"

namespace cr {

class Tree {
 private:
  Tree* parent;
  std::vector<Tree*> children;
  Board data;
  int heuristic;

 public:

  ~Tree();

  Tree();

  explicit Tree(Board data);

  Tree(Tree* parent, Board data);

  Tree(Board data, std::vector<Tree*> &children);

  Tree(Tree* parent, Board data, std::vector<Tree*>& children);

  const Board::size_type getSize() const;

  const Tree *getParent() const;

  Tree *getParent();

  void setParent(Tree *parent);

  const Board& getData() const;

  Board& getData();

  void setData(Board data);

  Tree* operator[](long index);

  const Tree* operator[](long index) const;

  const std::vector<Tree*>& getChildren() const;

  std::vector<Tree*>& getChildren();

  void setChildren(const std::vector<Tree*>& children);

  int getHeuristic() const;

  void setHeuristic(int heuristic);
};

}  // namespace cr

#endif  // CONNECTR_TREEBASIC_HPP_
