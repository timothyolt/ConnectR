// Copyright 2017 Timothy Oltjenbruns.

#ifndef CONNECTR_ITERATION1_TREEBASIC_HPP_
#define CONNECTR_ITERATION1_TREEBASIC_HPP_

#include <interface/ITree.hpp>
#include "Board2D.hpp"

namespace cr {
namespace iteration1 {

class TreeBasic : public interface::ITree<TreeBasic, Board2D> {
 private:
  node_type* parent;
  std::vector<node_type> children;
  data_type data;

 public:

  TreeBasic();

  explicit TreeBasic(data_type& data);

  TreeBasic(node_type* parent, data_type& data);

  TreeBasic(data_type& data, std::vector<node_type>& children);

  TreeBasic(node_type* parent, data_type& data, std::vector<node_type>& children);

  const node_type *getParent() const;

  node_type *getParent();

  void setParent(node_type *parent);

  const data_type& getData() const;

  data_type& getData();

  void setData(Board2D data);

  node_type &operator[](long index) override;

  const std::vector<node_type> &getChildren() const;

  void setChildren(const std::vector<node_type> &children);
};

}  // namespace iteration1
}  // namespace cr

#endif  // CONNECTR_ITERATION1_TREEBASIC_HPP_
