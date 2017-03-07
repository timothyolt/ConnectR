// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_ITERATION1_SOLVERBASIC_HPP_
#define CONNECTR_ITERATION1_SOLVERBASIC_HPP_

#include <interface/ISolver.hpp>
#include "Board2D.hpp"
#include "TreeBasic.hpp"

namespace cr {
/// \brief Namespace for standard connectR interfaces
namespace iteration1 {

class SolverBlank : public interface::ISolver<Board2D, TreeBasic> {
 public:
  short solve() override;
};

}  // namespace iteration1
}  // namespace cr

#endif  // CONNECTR_ITERATION1_SOLVERBASIC_HPP_
