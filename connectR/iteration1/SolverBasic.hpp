// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_ITERATION1_SOLVERBASIC_HPP_
#define CONNECTR_ITERATION1_SOLVERBASIC_HPP_

#include <interface/ISolver.hpp>
#include "Board2D.hpp"
#include "TreeBasic.hpp"

namespace cr {
/// \brief Namespace for standard connectR interfaces
namespace iteration1 {

class SolverBasic : public interface::ISolver<Board2D, TreeBasic> {
 private:
  tree_type tree;
  static void populate(tree_type* node, tree_type::data_type::size_type depth);
  static void evaluate(tree_type* node, tree_type::data_type::size_type depth);
 public:
  tree_type::data_type::size_type solve() override;
};

}  // namespace iteration1
}  // namespace cr

#endif  // CONNECTR_ITERATION1_SOLVERBASIC_HPP_
