// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_UTILS_HPP_
#define CONNECTR_UTILS_HPP_

#include <interface/ITree.hpp>
#include <stack>
#include <queue>

namespace cr {
namespace Helpers {
class TreeNodeIndex {
 public:
  const interface::ITree *pointer;
  std::vector<interface::ITree>::size_type index;
  TreeNodeIndex(const interface::ITree *pointer, std::vector<interface::ITree>::size_type index);
};
}

/// \brief            Depth-First Search using a Functional to evaluate the node
/// \param evaluate  Functional used to evaluate the node
/// \return           Const-pointer to first node matching the functional, or nullptr if not found
template <typename Functional>
const interface::ITree* searchDf(const interface::ITree *root, Functional evaluate) {
  std::stack<Helpers::TreeNodeIndex> stack;
  stack.emplace(root, 0);
  while (!stack.empty()) {
    auto cursor(stack.top().pointer);
    if (stack.top().index == 0 && evaluate(cursor))
      return cursor;
    if (stack.top().index < cursor->getSize()) {
      stack.emplace(&cursor->[stack.top().index++], 0);
    }
    else stack.pop();
  }
  return nullptr;
}

/// \brief            Breadth-First Search using a Functional to evaluate the node
/// \param evaluate   Functional used to evaluate the node
/// \return           Const-pointer to first node matching the functional, or nullptr if not found
template <typename Functional>
const interface::ITree* searchBf(const interface::ITree *root, Functional evaluate) {
  std::queue<Helpers::TreeNodeIndex> queue;
  queue.emplace(root, 0);
  while (!queue.empty()) {
    auto cursor(queue.front().pointer);
    if (evaluate(cursor))
      return cursor;
    for (auto i(0); i < cursor->getSize(); ++i)
      queue.emplace(&cursor->[i], 0);
    queue.pop();
  }
  return nullptr;
}

}  // namespace cr

#endif // CONNECTR_UTILS_HPP_
