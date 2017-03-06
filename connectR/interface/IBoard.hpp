// Copyright 2017 Tim Oltjenbruns.

#ifndef CONNECTR_INTERFACE_BOARD_HPP_
#define CONNECTR_INTERFACE_BOARD_HPP_

#include "BoardSize.hpp"

namespace cr {
/// \brief Namespace for standard connectR interfaces
namespace interface {

/// \brief        Interface for standard connect boards
/// \tparam TSize type of board container size, exposed through \p size_type
/// \tparam TData type of board space data, exposed through \p data_type
template <typename TSize, typename TData>
class IBoard {
 public:
  /// \brief type of board container size
  typedef TSize size_type;
  /// \brief type of board space data
  typedef TData data_type;
 private:
  /// \brief Holds the width, height, and connect specification
  BoardSize<size_type> size;
 protected:
  IBoard() : size(BoardSize<size_type>(0, 0, 0)) { }
  /// \brief          Creates a board initialized to empty
  /// \param size Width, height, and connect specification for the board
  explicit IBoard(BoardSize<size_type> size) : size(size) { }
  /// \brief        Copy constructor, copies board state into other
  /// \param origin Other board to copy data from
  explicit IBoard(const IBoard& origin) : size(origin.size) { }
 public:
  const BoardSize<size_type> &getSize() const {
    return size;
  }
  /// \brief        Get board state
  /// \param column column to read
  /// \param row    row to read
  /// \return       Board state at the position
  virtual const data_type get(size_type column, size_type row) const = 0;

  /// \brief        Drops a token into to board
  /// \param column Column to drop token into
  /// \param state  Which player token to drop
  virtual void drop(const size_type column, const data_type state) = 0;
};

}  // namespace interface
}  // namespace cr

#endif  // CONNECTR_INTERFACE_BOARD_HPP_
