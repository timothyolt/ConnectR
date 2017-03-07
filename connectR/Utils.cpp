// Copyright 2017 Timothy Oltjenbruns.

#include "Utils.hpp"

cr::Helpers::TreeNodeIndex::TreeNodeIndex(const interface::ITree *pointer,
                                          std::vector<interface::ITree>::size_type index)
    : pointer(pointer), index(index) { }
