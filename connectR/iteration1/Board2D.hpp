// Copyright 2017 Tim Oltjenbruns.

#ifndef CONNECTR_ITERATION1_BOARD_HPP_
#define CONNECTR_ITERATION1_BOARD_HPP_

#include <vector>
#include "interface/IBoard.hpp"

namespace cr {
/// \brief Namespace for Iteration 1: Basic 2D std::vector<bool> implementation
namespace iteration1 {

class Board2D : public interface::IBoard<short, bool> {
 private:
  /// \brief  Game board expressing each position as a pair of bits
  ///         0b00 = unset, 0b01 = player 1, 0b10 = player 2
  ///         \p width size vector of \p height * 2 size bitset vectors
  ///         Super awesome vector optimized as a bitset
  std::vector<std::vector<bool>> board;

 public:
  Board2D();
  /// \brief        Creates a board initialized to empty
  /// \param size   Width, height, and connect specification for the board
  explicit Board2D(interface::BoardSize<size_type> size);

  /// \brief        Copy constructor, copies board state into other
  ///               Deep copies the board using std::vector copy
  /// \param origin Other board to pull data from
  explicit Board2D(const Board2D& origin);

  /// \brief        Get board state
  /// \param column column to read
  /// \param row    row to read
  /// \return       Board state at the position
  const data_type get(size_type column, size_type row) const override;

  /// \brief        Drops a token into to board
  /// \param column Column to drop token into
  /// \param state  Which player token to drop
  void drop(const size_type column, const data_type state) override;
};

}  // namespace iteration1
}  // namespace cr

#endif  // CONNECTR_ITERATION1_BOARD_HPP_
