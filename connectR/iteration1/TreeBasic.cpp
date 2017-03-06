// Copyright 2017 timothyolt.

#include <assert.h>
#include "TreeBasic.hpp"

using std::vector;
using cr::iteration1::TreeBasic;
using node_type = cr::iteration1::TreeBasic::node_type;
using data_type = cr::iteration1::TreeBasic::data_type;

TreeBasic::TreeBasic()
    : parent(nullptr), data(), children({ }) { }

TreeBasic::TreeBasic(data_type& data)
    : parent(nullptr), data(data), children({ }) { }

TreeBasic::TreeBasic(node_type *parent, data_type& data)
    : parent(parent), data(data), children({ }) { }

TreeBasic::TreeBasic(data_type& data, std::vector<node_type>& children)
    : parent(nullptr), data(data), children(children) {
  assert(children.size() == 0 || children.size() == data.getSize().getWidth());
}

TreeBasic::TreeBasic(node_type *parent, data_type& data, std::vector<node_type>& children)
    : parent(parent), data(data), children(children) {
  assert(children.size() == 0 || children.size() == data.getSize().getWidth());
}

const node_type *TreeBasic::getParent() const {
  return parent;
}

node_type *TreeBasic::getParent() {
  return parent;
}

void TreeBasic::setParent(node_type *parent) {
  TreeBasic::parent = parent;
}

const data_type& TreeBasic::getData() const {
  return data;
}

data_type& TreeBasic::getData() {
  return data;
}

void TreeBasic::setData(Board2D data) {
  TreeBasic::data = data;
}

const vector<node_type> &TreeBasic::getChildren() const {
  return children;
}

void TreeBasic::setChildren(const vector<node_type> &children) {
  this->children = children;
}

node_type &TreeBasic::operator[](long index) {
  return children[index];
}
