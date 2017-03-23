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

bool promptOrder();

Board::size_type promptColumn(Board::size_type max);

Board::size_type promptWidth();
Board::size_type promptHeight();
Board::size_type promptConnect();
Board::size_type promptDepth();

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
  const auto width(promptWidth());
  const auto height(promptHeight());
  const auto connect(promptConnect());
  const auto depth(promptDepth());
  Board board(width, height, connect);
  const auto order(promptOrder());
  for (auto turn(0); turn < width * height; ++turn) {
    std::cout << "Turn " << turn << ": " << std::endl << board << std::endl;
    if ((turn & 1) ^ order)  // player
      board.drop(promptColumn(width));
    else  // computer
      board.drop(Solver(&board, depth).solve());
  }
}

void modeComputer() {
  const auto width(promptWidth());
  const auto height(promptHeight());
  const auto connect(promptConnect());
  const auto depth(promptDepth());
  Board board(width, height, connect);
  for (auto turn(0); turn < width * height; ++turn) {
    std::cout << "Turn " << turn << ": " << std::endl << board << std::endl;
    board.drop(Solver(&board, depth).solve());
  }
}

bool promptOrder() {
  std::string order("");
  while (order.empty()) {
    std::cout << "Player [1|f]irst or [2|s]econd?  ";
    std::cin >> order;
    if (!order.empty())
      switch (order[0]) {
        case '1':
        case 'f': return true;
        case '2':
        case 's': return false;
        default:
          std::cout << "Unknown order \"" << order << "\"" << std::endl;
          break;
      }
  }
  return false;
}

Board::size_type promptColumn(Board::size_type max) {
  Board::size_type column(0);
  while (true) {
    std::cout << "Enter a column [1..." << max << "]: ";
    if (std::cin >> column && column >= 1 && column <= max)
      return column - 1;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

Board::size_type promptWidth() {
  Board::size_type width(0);
  while (true) {
    std::cout << "Enter a width: ";
    if (std::cin >> width)
      return width;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

Board::size_type promptHeight() {
  Board::size_type height(0);
  while (true) {
    std::cout << "Enter a height: ";
    if (std::cin >> height)
      return height;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

Board::size_type promptConnect() {
  Board::size_type connect(0);
  while (true) {
    std::cout << "Enter a connect: ";
    if (std::cin >> connect)
      return connect;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

Board::size_type promptDepth() {
  Board::size_type depth(0);
  while (true) {
    std::cout << "Enter a depth: ";
    if (std::cin >> depth)
      return depth;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}
