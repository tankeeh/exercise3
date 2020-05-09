//
// Created by Antonio on 30/04/2020.
//

#ifndef EXERCISE2_TREEUTILSFUNCTIONS_HPP
#define EXERCISE2_TREEUTILSFUNCTIONS_HPP
#include "../../binarytree/binarytree.hpp"
#include "../UtilityFunctions/commons/commons.hpp"

template <typename Data>
void PrintElementTree(const Data& elem, void*);

template <typename Data>
void TriplicateIntForBinaryTree(BinaryTree<Data>& tree);

#include "TreeUtilsFunctions.cpp"
#endif //EXERCISE2_TREEUTILSFUNCTIONS_HPP
