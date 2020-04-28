
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec { // Should extend BinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;

  // ...

public:

  // using BinaryTree<Data>::???;

  struct NodeVec { // Should extend Node

  private:

    // ...

  protected:

    // ...

  public:

    // friend class BinaryTreeVec<Data>;

    /* ********************************************************************** */

    // Specific member functions

    // type HasParent() specifiers;
    // type HasLeftSibling() specifiers;
    // type HasRightSibling() specifiers;

    // type Parent() specifiers; // (might throw std::out_of_range)
    // type LeftSibling() specifiers; // (might throw std::out_of_range)
    // type RightSibling() specifiers; // (might throw std::out_of_range)

    /* ********************************************************************** */

    // Specific member functions (inherited from Node)

    // type Element() specifiers; // Override Node member Mutable access to the element
    // type Element() specifiers; // Override Node member Immutable access to the element

    // type IsLeaf() specifiers; // Override Node member
    // type HasLeftChild() specifiers; // Override Node member
    // type HasRightChild() specifiers; // Override Node member

    // type LeftChild() specifiers; // Override Node member (might throw std::out_of_range)
    // type RightChild() specifiers; // Override Node member (might throw std::out_of_range)

  };

  /* ************************************************************************ */

  // Default constructor
  // BinaryTreeVec() specifiers;

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // Construct a tree with a given root data (Copy of the value)
  // BinaryTreeVec(argument) specifiers; // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;

  // Move constructor
  // BinaryTreeVec(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override Node member (might throw std::length_error)
  // type NewRoot(argument) specifiers; // Override Node member (Copy of the value)
  // type NewRoot(argument) specifiers; // Override Node member (Move of the value)

  // type AddLeftChild(arguments) specifiers; // Add a child to a given node (Copy of the value)
  // type AddLeftChild(arguments) specifiers; // Add a child to a given node (Move of the value)
  // type AddRightChild(arguments) specifiers; // Add a child to a given node (Copy of the value)
  // type AddRightChild(arguments) specifiers; // Add a child to a given node (Move of the value)

  // type RemoveLeftChild(argument) specifiers; // Remove an entire subtree rooted in a child of a given node
  // type RemoveRightChild(argument) specifiers; // Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  // using typename BinaryTree<Data>::MapFunctor;
  // type MapBreadth(arguments) specifiers; // Override BreadthSearchableContainer member

  // using typename BinaryTree<Data>::FoldFunctor;
  // type FoldBreadth(arguments) specifiers; // Override BreadthSearchableContainer member

protected:

  // type Expand() specifiers; // Accessory function
  // type Reduce() specifiers; // Accessory function

  // ...

};

/* ************************************************************************** */

#include "binarytreevec.cpp"

}

#endif
