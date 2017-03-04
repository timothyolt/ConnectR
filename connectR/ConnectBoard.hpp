// Copyright 2017 Tim Oltjenbruns.

#ifndef XMLPARSER_CONNECTBOARD_HPP_
#define XMLPARSER_CONNECTBOARD_HPP_

class ConnectBoard {
 private:
  /// \brief  Board width in game spaces
  int width;
  /// \brief  Board height in game spaces
  int height;
  /// \brief  Number of connected spaces to win
  int connect;
  /// \brief  Unset board value
  const char bUnset(0b00);
  /// \brief  Player one board value
  const char bPlayer1(0b01);
  /// \brief  Player 2 Board value
  const char bPlayer2(0b10)
  /// \brief  Game board expressing each position as a pair of bits
  ///         0b00 = unset, 0b01 = player 1, 0b10 = player 2
  ///         \p width size vector of \p height * 2 size bitset vectors
  ///         Super awesome vector optimized as a bitset
  std::vector<std::vector<bool>> board;
};

#endif  // XMLPARSER_CONNECTBOARD_HPP_
