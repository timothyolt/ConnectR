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
  std::vector<node_type*> children;
  data_type data;
  int heuristic;

 public:

  ~TreeBasic();

  TreeBasic();

  explicit TreeBasic(data_type data);

  TreeBasic(node_type* parent, data_type data);

  TreeBasic(data_type data, std::vector<node_type*> &children);

  TreeBasic(node_type* parent, data_type data, std::vector<node_type*>& children);

  const size_type getSize() const override;

  const node_type *getParent() const override;

  node_type *getParent() override;

  void setParent(node_type *parent) override;

  const data_type& getData() const override;

  data_type& getData() override;

  void setData(Board2D data) override;

  node_type* operator[](long index) override;

  const node_type* operator[](long index) const override;

  const std::vector<node_type*>& getChildren() const;

  std::vector<node_type*>& getChildren();

  void setChildren(const std::vector<node_type*>& children);

  int getHeuristic() const;

  void setHeuristic(int heuristic);
};

}  // namespace iteration1
}  // namespace cr

#endif  // CONNECTR_ITERATION1_TREEBASIC_HPP_
