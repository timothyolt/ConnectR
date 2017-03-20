// Copyright 2017 Tim Oltjenbruns.

#ifndef CONNECTR_BOARD_HPP_
#define CONNECTR_BOARD_HPP_

#include <vector>
#include <ostream>
#include <boost/dynamic_bitset.hpp>

namespace cr {

class Board;

std::ostream &operator<<(std::ostream &os, const Board &d);

class Board {
 public:
  /// \brief type of board container size
  typedef boost::dynamic_bitset<>::size_type size_type;
  typedef long score_type;
 private:
  /// \brief  Board width in game spaces
  const size_type width;
  /// \brief  Board height in game spaces
  const size_type height;
  /// \brief  Number of connected spaces to win
  const size_type connect;

  const size_type area;
  /// \brief  Game board expressing each position as a pair of bits
  ///         0b00 = unset, 0b01 = player 1, 0b10 = player 2
  ///         \p width size vector of \p height * 2 size bitset vectors
  ///         Super awesome vector optimized as a bitset
  //std::vector<std::vector<short>> board;
  boost::dynamic_bitset<> board[2];
  boost::dynamic_bitset<> cushion;
  size_type count;
  size_type* columnHeight;
  size_type* history;

  boost::dynamic_bitset<>::size_type shiftCount(boost::dynamic_bitset<>::size_type shift) const;

 public:
  ~Board();

  Board();

  Board(size_type width, size_type height, size_type connect);

  /// \brief        Copy constructor, copies board state into other
  ///               Deep copies the board using std::vector copy
  /// \param origin Other board to pull data from
  explicit Board(const Board* origin);

  size_type getWidth() const;
  size_type getHeight() const;
  size_type getConnect() const;

  /// \brief        Drops a token into to board
  /// \param column Column to drop token into
  /// \param state  Which player token to drop
  void drop(const size_type column);

  void undo();

  score_type score() const;

  std::string toString() const;

  friend std::ostream &operator<<(std::ostream &os, const Board &d);
};

}  // namespace cr

#endif  // CONNECTR_BOARD_HPP_
