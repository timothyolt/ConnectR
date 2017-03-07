// Copyright 2017 Timothy Oltjenbruns.

#include <Utils.hpp>
#include "SolverBasic.hpp"

short cr::iteration1::SolverBasic::solve() {
  searchDf(&tree, [](const TreeBasic* tree) { return false; });
  return 0;
}
