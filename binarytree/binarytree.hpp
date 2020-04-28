
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: public virtual BreadthSearchableContainer<Data> {

private:

  // ...

protected:

  using BreadthSearchableContainer<Data>::size;

  // ...

public:

    struct Node {

    private:

    // ...

    protected:

        Data* val = nullptr;
        Node* sx = nullptr;
        Node* dx = nullptr;
    // ...

    public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element
    virtual Data& Element() const noexcept = 0; // Immutable access to the element

    virtual bool IsLeaf() const noexcept = 0;
    virtual bool HasLeftChild() const noexcept = 0;
    virtual bool HasRightChild() const noexcept = 0 ;

    virtual Node& LeftChild() const = 0; // (might throw std::out_of_range)
    virtual Node& RightChild() const = 0; // (might throw std::out_of_range)

  };

  /* ************************************************************************ */

  // Destructor
  ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual BinaryTree& operator=(BinaryTree&) = 0; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual BinaryTree& operator=(BinaryTree&&) = 0; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(BinaryTree& ) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(BinaryTree& ) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Node& Root() const = 0; // (might throw std::length_error)

  //i due metodi successivi possono ragionevolemnte, qualora già esistesse la radice dell'albero,
  //pulire l' albero precedente e assegnarre la nuova radice passata come parametro;
  virtual Node& NewRoot(Data&) const noexcept = 0 ; // Copy of the value
  virtual Node& NewRoot(Data&&) const noexcept = 0;// Move of the value

  using typename SearchableContainer<Data>::MapFunctor;
  //void MapInOrder(arguments) specifiers;

  using typename SearchableContainer<Data>::FoldFunctor;
  //void FoldInOrder(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  // type MapPreOrder(arguments) specifiers; // Override SearchableContainer member
  // type MapPostOrder(arguments) specifiers; // Override SearchableContainer member

  // type FoldPreOrder(arguments) specifiers; // Override SearchableContainer member
  // type FoldPostOrder(arguments) specifiers; // Override SearchableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  // type MapBreadth(arguments) specifiers; // Override BreadthSearchableContainer member

  // type FoldBreadth(arguments) specifiers; // Override BreadthSearchableContainer member

protected:

  // type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  // type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

  // type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  // type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

#include "binarytree.cpp"

}

#endif
