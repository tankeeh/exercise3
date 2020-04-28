
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */
typedef unsigned int uint;



#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template<typename Data>
    class Vector : public LinearContainer<Data>, public SearchableContainer<Data> {

    private:

        // ...

    protected:

        using LinearContainer<Data>::size;
        Data *elem = nullptr;
        // ...

    public:


        // Default constructor
        Vector();


        // Specific constructor
        Vector(uint dimension);


        // Copy constructor
        Vector(const Vector &);


        // Move constructor
        Vector(Vector &&) noexcept;

        /* ************************************************************************ */

        // Destructor
        ~Vector() noexcept;

        /* ************************************************************************ */

        // Copy assignment
        Vector &operator=(const Vector &vec);


        // Move assignment
        Vector &operator=(Vector &&vec);

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(const Vector &) const noexcept;

        // type operator!=(argument) specifiers;
        bool operator!=(const Vector &) const noexcept;

        /* ************************************************************************ */

        // Specific member functions
        void Resize(uint newSize);

        /* ************************************************************************ */

        // Specific member functions (inherited from Container)
        void Clear() override;

        /* ************************************************************************ */

        // Specific member functions (inherited from LinearContainer)
        Data Front() const override;

        Data Back() const override;


        // type operator[](argument) specifiers; // Override LinearContainer member
        Data &operator[](const unsigned int position) override;

        /* ************************************************************************ */

        // Specific member functions (inherited from SearchableContainer)

        using typename SearchableContainer<Data>::MapFunctor;
        void MapPreOrder(MapFunctor function, void *par) override; // Override SearchableContainer member
        void MapPostOrder(MapFunctor function, void *par) override;  // Override SearchableContainer member


        using typename SearchableContainer<Data>::FoldFunctor;
        void FoldPreOrder(FoldFunctor, const void *, void *) const override; // Override SearchableContainer member
        void FoldPostOrder(FoldFunctor, const void *, void *) const override;  // Override SearchableContainer member

        //type PrintFunction()
        void print();

        using SearchableContainer<Data>::Exists;

        //Map Functions
        void PrintPreorder();
        void PrintPostorder();


    };

/* ************************************************************************** */

#include "vector.cpp"


}
#endif
