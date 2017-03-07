// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_INTERFACE_BOARDSIZE_HPP_
#define CONNECTR_INTERFACE_BOARDSIZE_HPP_

namespace cr {
/// \brief Namespace for standard connectR interfaces
namespace interface {

/// \brief Specifies size parameters for a connect board
/// \tparam TSize type of board container size
template <typename TSize>
struct BoardSize {
 private:
  /// \brief  Board width in game spaces
  TSize width;
  /// \brief  Board height in game spaces
  TSize height;
  /// \brief  Number of connected spaces to win
  TSize connect;

 public:
  TSize getWidth() const {
    return width;
  }

  TSize getHeight() const {
    return height;
  }

  TSize getConnect() const {
    return connect;
  }

  BoardSize()
      : width(0), height(0), connect(0) { }

  /// \brief          Create size struct
  /// \param width    Board width in game spaces
  /// \param height   Board height in game spaces
  /// \param connect  Number of connected spaces to win
  BoardSize(TSize width, TSize height, TSize connect)
      : width(width), height(height), connect(connect) {}
};

}
}

#endif // CONNECTR_INTERFACE_BOARDSIZE_HPP_
