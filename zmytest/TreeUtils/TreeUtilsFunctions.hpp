//
// Created by Antonio on 30/04/2020.
//

#ifndef EXERCISE2_TREEUTILSFUNCTIONS_HPP
#define EXERCISE2_TREEUTILSFUNCTIONS_HPP

#include "../../binarytree/binarytree.hpp"
#include "../UtilityFunctions/commons/commons.hpp"
//#include "../../binarytree/lnk/binarytreelnk.hpp"


template <typename Data>
void PrintElementTreePreOrder(lasd::BinaryTree<Data>& tree);

template <typename Data>
void TriplicateIntForBinaryTree(lasd::BinaryTree<Data>& tree);

template <typename Data>
void InitialConcatStringForBinaryTree(lasd::BinaryTree<Data>& tree, void* par);

template <typename Data>
void PrintElementTreeBreadth(lasd::BinaryTree<Data>& tree);

template <typename Data>
void PrintElementTreeInOrder(lasd::BinaryTree<Data>& tree);

template <typename Data>
void PrintElementTreePostOrder(lasd::BinaryTree<Data>& tree);

template <typename Data>
Data FoldTreeIntMoltiplicateSmallerThan(const Data& par, lasd::BinaryTree<Data> &tree);

template <typename Data>
Data FoldTreeFloatSumBiggerThan(const Data& par, lasd::BinaryTree<Data> &tree);

template <typename Data>
Data FoldTreeStringConcatLowerEqualsThan(const Data& par, lasd::BinaryTree<Data> &tree);


#include "TreeUtilsFunctions.cpp"
#endif //EXERCISE2_TREEUTILSFUNCTIONS_HPP
