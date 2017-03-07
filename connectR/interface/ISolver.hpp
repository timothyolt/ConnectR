// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_INTERFACE_ISOLVER_HPP_
#define CONNECTR_INTERFACE_ISOLVER_HPP_

#include "IBoard.hpp"
#include "ITree.hpp"

namespace cr {
/// \brief Namespace for standard connectR interfaces
namespace interface {

template <typename TBoard, typename TTree>
class ISolver {
 public:
  typedef TBoard board_type;
  typedef TTree tree_type;
 private:
  TBoard start;
  TTree tree;
  bool player;
 protected:
  ISolver() : start(), tree(), player(false) {}
  ISolver(TBoard start, bool player) : start(start), tree(tree_type()), player(player) { };
 public:

  virtual board_type::size_type solve() = 0;
};

}  // namespace interface
}  // namespace cr

#endif // CONNECTR_INTERFACE_ISOLVER_HPP_
