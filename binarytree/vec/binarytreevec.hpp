
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data> {

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  // ...

public:

  // using BinaryTree<Data>::???;


struct NodeVec : virtual public BinaryTree<Data>::Node {

  private:

    // ...

  protected:

      Data* val = nullptr;
      int curr_index = 0;
      Vector<Data*>& treevec;   //riferimento al vettore

  public:

      //constructors del NodeVec
    NodeVec() = default;

    NodeVec(const Data& item); //COPY CONSTRUCTOR

    NodeVec(Data&& item); //MOVE CONSTRUCTOR

    ~NodeVec();



    friend class BinaryTreeVec<Data>;

    /* ********************************************************************** */

    // Specific member functions

    bool HasParent() const noexcept ;
    bool HasLeftSibling() const noexcept ;
    bool HasRightSibling() const noexcept ;

    NodeVec& Parent() const; // (might throw std::out_of_range)
    NodeVec& LeftSibling() const; // (might throw std::out_of_range)
    NodeVec& RightSibling() const; // (might throw std::out_of_range)

    /* ********************************************************************** */

    // Specific member functions (inherited from Node)

    const Data& Element() const noexcept override; // Override Node member Mutable access to the element
    Data& Element() noexcept override ; // Override Node member Immutable access to the element

    bool IsLeaf() const noexcept override; // Override Node member
    bool HasLeftChild() const noexcept override ; // Override Node member
    bool HasRightChild() const noexcept override ; // Override Node member


    //I due nodi successivi avranno degli overload const che specificheranno che la struttura
    //chiamante non venga modificata e così anche il nodo stesso ritornato

    NodeVec& LeftChild() override ; // Override Node member (might throw std::out_of_range)
    NodeVec& RightChild() override; // Override Node member (might throw std::out_of_range)

    const NodeVec& LeftChild() const ; // (might throw std::out_of_range)
    const NodeVec& RightChild() const; // (might throw std::out_of_range)

  };

  /* ************************************************************************ */

  Vector<Data*> tree;


  // Default constructor
   BinaryTreeVec() = default;

  // Specific constructors
  //BinaryTreeVec(const BinaryTreeVec&); // Construct a tree with a given root data (Copy of the value)
  //BinaryTreeVec(BinaryTreeVec&&);  // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&) ;

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) ;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&) noexcept ;

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept ;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(BinaryTreeVec&) const noexcept ;
  bool operator!=(BinaryTreeVec&) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() override; // Override Node member (might throw std::length_error)
  const NodeVec& Root() const override;
  void NewRoot(const Data&) noexcept override; // Override Node member (Copy of the value)
  void NewRoot(Data&&) noexcept override; // Override Node member (Move of the value)

  void AddLeftChild(const NodeVec& node) noexcept ; // Add a child to a given node (Copy of the value)
  void AddLeftChild(NodeVec&& node) noexcept ; // Add a child to a given node (Move of the value)
  void AddRightChild(const NodeVec& node) noexcept ; // Add a child to a given node (Copy of the value)
  void AddRightChild(NodeVec&& node) noexcept ; // Add a child to a given node (Move of the value)

  void RemoveLeftChild(NodeVec& node) const noexcept ; // Remove an entire subtree rooted in a child of a given node
  void RemoveRightChild(NodeVec& node) const noexcept ;// Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() noexcept override ; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)

  using typename BinaryTree<Data>::MapFunctor;
  void MapBreadth(MapFunctor fun ,void* par) override ; // Override BreadthSearchableContainer member

  using typename BinaryTree<Data>::FoldFunctor;
  void FoldBreadth(FoldFunctor fun,const void* par,void* acc) const override; // Override BreadthSearchableContainer member

protected:

  void Expand() noexcept ; // Accessory function
  void Reduce() noexcept ; // Accessory function

  // ...

};



/* ************************************************************************** */

#include "binarytreevec.cpp"

}

#endif
