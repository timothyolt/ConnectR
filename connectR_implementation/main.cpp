// Copyright 2017 Timothy Oltjenbruns

#include <iostream>
#include <Board.hpp>
#include <Solver.hpp>

using cr::Board;
using cr::Tree;
using cr::Solver;

enum play_mode {
  player, computer, exitProgram
};

play_mode promptPlayMode();

void modePlayer();

void modeComputer();

Board::size_type promptColumn(Board::size_type max);

int main(int argCount, char* args[]) {
  std::cout << "Hello ConnectR World!" << std::endl;
  srand((unsigned int) time(0));
  while (true) {
    switch (promptPlayMode()) {
      case player: modePlayer(); break;
      case computer: modeComputer(); break;
      case exitProgram: return 0;
    }
  }
}

play_mode promptPlayMode() {
  std::string mode("");
  while (mode.empty()) {
    std::cout << "Mode [p]layer vs. computer or [c]omputer vs. computer or [e]xit: ";
    std::cin >> mode;
    if (!mode.empty())
    switch (mode[0]) {
      case 'p': return player;
      case 'c': return computer;
      case 'e': return exitProgram;
      default:
        std::cout << "Unknown mode \"" << mode << "\"" << std::endl;
        break;
    }
  }
  return exitProgram;
}

void modePlayer() {
  Board board(7, 6, 4);
  for (auto turn(0); turn < 42; ++turn) {
    std::cout << "Turn " << turn << ": " << std::endl << board << std::endl;
    if ((turn & 1) == 0)  // player
      board.drop(promptColumn(6));
    else  // computer
      board.drop(Solver(&board).solve());
  }
}

void modeComputer() {
  Board board(7, 6, 4);
  for (auto turn(0); turn < 42; ++turn) {
    std::cout << "Turn " << turn << ": " << std::endl << board << std::endl;
    board.drop(Solver(&board).solve());
  }
}

Board::size_type promptColumn(Board::size_type max) {
  Board::size_type column(0);
  while (true) {
    std::cout << "Enter a column [0..." << max << "]: ";
    if (!(std::cin >> column) || column < 0 || column > max) continue;
    return column;
  }
}
