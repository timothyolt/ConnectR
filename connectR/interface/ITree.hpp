// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_INTERFACE_ITREE_HPP_
#define CONNECTR_INTERFACE_ITREE_HPP_

#include <vector>
#include "IBoard.hpp"

namespace cr {
/// \brief Namespace for standard connectR interfaces
namespace interface {

template <typename TNode, typename TData>
class ITree {
 public:
  /// \brief type of tree
  typedef TNode node_type;
  /// \brief type of tree data
  typedef TData data_type;
  typename TData::size_type typedef size_type;
 public:
  virtual const size_type getSize() const = 0;

  virtual const node_type* getParent() const = 0;

  virtual node_type* getParent() = 0;

  virtual void setParent(node_type *parent) = 0;

  virtual const data_type& getData() const = 0;

  virtual data_type& getData() = 0;

  virtual void setData(data_type data) = 0;

  virtual node_type* operator[] (long index) = 0;

  virtual const node_type* operator[] (long index) const = 0;
};

}  // namespace interface
}  // namespace cr

#endif // CONNECTR_INTERFACE_ITREE_HPP_
