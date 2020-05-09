//
// Created by Antonio on 30/04/2020.
//

#ifndef EXERCISE2_TREEUTILSFUNCTIONS_HPP
#define EXERCISE2_TREEUTILSFUNCTIONS_HPP
#include "../../binarytree/binarytree.hpp"
#include "../UtilityFunctions/commons/commons.hpp"

template <typename Data>
void PrintElementTreePreOrder(BinaryTree<Data>& tree);

template <typename Data>
void TriplicateIntForBinaryTree(BinaryTree<Data>& tree);

template <typename Data>
void InitialConcatStringForBinaryTree(BinaryTree<Data>& tree);

template <typename Data>
void PrintElementTreeBreadth(BinaryTree<Data>& tree);

template <typename Data>
void PrintElementTreeInOrder(BinaryTree<Data>& tree);

template <typename Data>
void PrintElementTreePostOrder(BinaryTree<Data>& tree);

template <typename Data>
Data FoldTreeIntMoltiplicateSmallerThan(const Data& par, BinaryTree<Data> &tree);

template <typename Data>
Data FoldTreeFloatSumBiggerThan(const Data& par, BinaryTree<Data> &tree);

template <typename Data>
Data FoldTreeStringConcatLowerEqualsThan(const Data& par, BinaryTree<Data> &tree);

#include "TreeUtilsFunctions.cpp"
#endif //EXERCISE2_TREEUTILSFUNCTIONS_HPP
