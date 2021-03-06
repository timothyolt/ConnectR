// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_UTILS_HPP_
#define CONNECTR_UTILS_HPP_

#include <stack>
#include <queue>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include "Board.hpp"

namespace cr {
namespace Helpers {

template <typename TTree>
class ConstTreeNodeIndex {
 public:
  const TTree *pointer;
  typename std::vector<TTree>::size_type index;
  ConstTreeNodeIndex(const TTree *pointer, typename std::vector<TTree>::size_type index)
      : pointer(pointer), index(index) { }
};

template <typename TTree>
class TreeNodeIndex {
 public:
  TTree *pointer;
  typename std::vector<TTree>::size_type index;
  TreeNodeIndex(TTree *pointer, typename std::vector<TTree>::size_type index)
      : pointer(pointer), index(index) { }
};

}

/// \brief            Depth-First Search using a Functional to evaluate the node
/// \param evaluate  Functional used to evaluate the node
/// \return           Const-pointer to first node matching the functional, or nullptr if not found
template <typename TTree, typename Functional>
const TTree* searchDf(const TTree *root, Functional evaluate) {
  std::stack<Helpers::ConstTreeNodeIndex<TTree>> stack;
  stack.emplace(root, 0);
  while (!stack.empty()) {
    auto cursor(stack.top().pointer);
    if (stack.top().index == 0 && evaluate(cursor))
      return cursor;
    if (stack.top().index < cursor->getSize()) {
      stack.emplace(&cursor->operator[](stack.top().index++), 0);
    }
    else stack.pop();
  }
  return nullptr;
}

template <typename TTree, typename NodeDepthAction, typename NodePlayerAction>
void miniMax(TTree *root, Board::size_type maxDepth, NodeDepthAction populate, NodePlayerAction evaluate, NodePlayerAction propagate) {
  auto startPlayer(root->getData()->getCount() & 1);
  std::stack<Helpers::TreeNodeIndex<TTree>> stack;
  stack.emplace(root, 0);
  populate(root, stack.size());
  while (!stack.empty()) {
    auto cursor(stack.top().pointer);
    auto index(stack.top().index);
    if (cursor == nullptr)
      stack.pop();
    else if (index < cursor->size) {
      auto child((*cursor)[stack.top().index++]);
      stack.emplace(child, 0);
      if (child != nullptr && stack.size() <= maxDepth)
        populate(child, stack.size()); // populate next generation
    }
    else {
      if (cursor->empty())
        evaluate(cursor, (stack.size() & 1) ^ startPlayer);
      else
        propagate(cursor, (stack.size() & 1) ^ startPlayer);
      stack.pop();
    }
  }
  return;
}

/// \brief            Breadth-First Search using a Functional to evaluate the node
/// \param evaluate   Functional used to evaluate the node
/// \return           Const-pointer to first node matching the functional, or nullptr if not found
template <typename TTree, typename Functional>
const TTree* searchBf(const TTree *root, Functional evaluate) {
  std::queue<Helpers::ConstTreeNodeIndex<TTree>> queue;
  queue.emplace(root, 0);
  while (!queue.empty()) {
    auto cursor(queue.front().pointer);
    if (evaluate(cursor))
      return cursor;
    for (auto i(0); i < cursor->getSize(); ++i)
      queue.emplace(&cursor->operator[](i), 0);
    queue.pop();
  }
  return nullptr;
}

}  // namespace cr

#endif // CONNECTR_UTILS_HPP_
