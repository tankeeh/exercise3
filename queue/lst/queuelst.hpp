
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: virtual public Queue<Data>, virtual protected List<Data>{ // Should extend Queue<Data> and List<Data>

private:

  // ...

protected:

    using List<Data>::size;
    using List<Data>::node;

  // ...

public:

  // Default constructor
  QueueLst() = default;

  // Copy constructor
  QueueLst(const QueueLst& queue);

  // Move constructor
  QueueLst(QueueLst&& queue);

  /* ************************************************************************ */

  // Destructor
  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst& operator=(const QueueLst& queue);

  // Move assignment
  QueueLst& operator=(QueueLst&& queue);


    /* ************************************************************************ */

  // Comparison operators
  bool operator==(QueueLst& queue);
  bool operator!=(QueueLst& queue);


  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

    virtual Data Head() const override ; // (might throw std::length_error)
    virtual void Dequeue() override; // (might throw std::length_error)
    virtual Data HeadNDequeue() override; // (might throw std::length_error)
    virtual void Enqueue(Data&) noexcept override; // Copy of the value
    virtual void Enqueue(Data&&) noexcept override;// Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    using Container::Empty;

    using Container::Size;
    /* ************** */
    using List<Data>::Clear;

};

/* ************************************************************************** */

#include "queuelst.cpp"

}

#endif
