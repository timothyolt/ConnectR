// Copyright 2017 Tim Oltjenbruns.

#ifndef CONNECTR_BOARD_HPP_
#define CONNECTR_BOARD_HPP_

#include <vector>
#include <ostream>

namespace cr {

class Board;

std::ostream &operator<<(std::ostream &os, const Board &d);

class Board {
 public:
  /// \brief type of board container size
  typedef int size_type;
  /// \brief type of board space data
  typedef short data_type;
 private:
  /// \brief  Board width in game spaces
  size_type width;
  /// \brief  Board height in game spaces
  size_type height;
  /// \brief  Number of connected spaces to win
  size_type connect;
  /// \brief  Game board expressing each position as a pair of bits
  ///         0b00 = unset, 0b01 = player 1, 0b10 = player 2
  ///         \p width size vector of \p height * 2 size bitset vectors
  ///         Super awesome vector optimized as a bitset
  std::vector<std::vector<short>> board;

 public:
  Board();

  Board(size_type width, size_type height, size_type connect);

  /// \brief        Copy constructor, copies board state into other
  ///               Deep copies the board using std::vector copy
  /// \param origin Other board to pull data from
  explicit Board(const Board* origin);

  size_type getWidth() const;
  size_type getHeight() const;
  size_type getConnect() const;

  /// \brief        Get board state
  /// \param column column to read
  /// \param row    row to read
  /// \return       Board state at the position
  const data_type get(size_type column, size_type row) const;

  /// \brief        Drops a token into to board
  /// \param column Column to drop token into
  /// \param state  Which player token to drop
  void drop(const size_type column, const data_type state);

  friend std::ostream &operator<<(std::ostream &os, const Board &d);
};

}  // namespace cr

#endif  // CONNECTR_BOARD_HPP_
