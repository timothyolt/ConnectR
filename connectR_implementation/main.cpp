// Copyright 2017 Timothy Oltjenbruns

#include <iostream>
#include <iteration1/Board2D.hpp>
#include <iteration1/TreeBasic.hpp>
#include <iteration1/SolverBasic.hpp>

using cr::interface::BoardSize;
using cr::iteration1::Board2D;
using cr::iteration1::TreeBasic;
using cr::iteration1::SolverBasic;

int main(int argCount, char* args[]) {
  std::cout << "Hello ConnectR World!" << std::endl;
  srand((unsigned int) time(0));
  Board2D start(BoardSize<short>((short) 7, (short) 6, (short) 4));
  SolverBasic solver(start, true);
  solver.solve();
}
