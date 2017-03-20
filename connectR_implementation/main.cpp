// Copyright 2017 Timothy Oltjenbruns

#include <iostream>
#include <Board.hpp>
#include <Tree.hpp>
#include <Solver.hpp>

using cr::Board;
using cr::Tree;
using cr::Solver;

int main(int argCount, char* args[]) {
  std::cout << "Hello ConnectR World!" << std::endl;
  srand((unsigned int) time(0));
  Board start(7, 6, 4);
  Solver solver(&start, true);
  solver.solve();
}
