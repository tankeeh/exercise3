//
// Created by Antonio on 23/04/2020.
//


#include <iostream>
#include <algorithm>
#include <cmath>
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
#include "../RandomGens/RandomValues.hpp"
//#include "stack/lst/stacklst.hpp"
//#include "queue/lst/queuelst.hpp"
//#include "stack/vec/stackvec.hpp"
//#include "queue/vec/queuevec.hpp"


/* ************************************************************************** */

/**FUNZIONI MAP BY ME**/

//FUNZIONE DI DUPLICAZIONE PER VETTORI E LISTE
template <typename Data>
void DuplicateInt(Data& elem, void*){
    elem = elem*2;
}
template <typename Data>
void DuplicateIntVectorPreOrder(lasd::Vector<Data> &vettore){
    vettore.MapPreOrder(DuplicateInt<Data>, nullptr);
}
template <typename Data>
void DuplicateIntListPreOrder(lasd::List<Data> &list){
    list.MapPreOrder(DuplicateInt<Data>, nullptr);
}




//FUNZIONE QUADRATO PER VETTORI E LISTE
template <typename Data>
void SquaredFloat(Data& elem, void* par){
    elem *= elem;
    elem = round(elem*1000)/1000;
}
template <typename Data>
void SquareFloatVectorPreOrder(lasd::Vector<Data> &vettore){
    vettore.MapPreOrder(&SquaredFloat<Data>, nullptr);
}
template <typename Data>
void SquareFloatListPreOrder(lasd::List<Data> &list){
    list.MapPreOrder(&SquaredFloat<Data>, nullptr);
}




//FUNZIONE DI UPPER CASE PER VETTORI E LISTE
template <typename Data>
void UpperCase(Data& elem, void* par){
    std::transform(elem.begin(), elem.end(),elem.begin(), ::toupper);
}
template <typename Data>
void UppercaseVectorPreOrder(lasd::Vector<Data> &vettore){
    vettore.MapPreOrder(&UpperCase<Data>, nullptr);
}
template <typename Data>
void UppercaseListPreOrder(lasd::List<Data> &list){
    list.MapPreOrder(&UpperCase<Data>, nullptr);
}





/**FUNZIONI DI FOLD BY ME**/

//FOLD PER INTERI
template <typename Data>
void Sum(const Data & dat, const void* par, void *acc) {
    if (dat < *(int*)par){
        *(int*)acc += dat;
    }
}
template <typename Data>
Data FoldIntVectorSumLowerThan(const Data par, lasd::Vector<Data> &vettore) {
    Data acc = 0;
    vettore.FoldPreOrder(&Sum<Data>,&par,&acc);
    return acc;
}
template <typename Data>
Data FoldIntListSumLowerThan(const Data par, lasd::List<Data> &list) {
    Data acc = 0;
    list.FoldPreOrder(&Sum<Data>,&par,&acc);
    return acc;
}



//FOLD PER FLOAT
template <typename Data>
void MoltiplicateFloat(const Data & dat, const void* par, void *acc) {
    if (dat > *(Data*)par){
        *(Data*)acc *= dat;
    }
}
template <typename Data>
Data FoldFloatVectorMoltiplicateBiggerThan(const Data par, lasd::Vector<Data> &vettore) {
    Data acc = 1;
    vettore.FoldPreOrder(&MoltiplicateFloat<Data>,&par,&acc);
    return acc;
}
template <typename Data>
Data FoldFloatListMoltiplicateBiggerThan(const Data par, lasd::List<Data> &list) {
    float acc = 1.0f;
    list.FoldPreOrder(&MoltiplicateFloat<Data>,&par,&acc);
    return acc;
}




//FOLD PER STRINGHE
template <typename Data>
void StringConcat(const Data & dat, const void* par, void *acc) {
    if (dat.length() <= *(int*)par){
        *(Data*)acc += dat;
    }
}

template <typename Data>
Data FoldStringVectorConcatLowerEquals(const int par, lasd::Vector<Data> &vettore) {
    std::string acc = "";
    vettore.FoldPreOrder(&StringConcat<Data>,&par,&acc);
    return acc;
}

template <typename Data>
Data FoldStringListConcatLowerEquals(const int par, lasd::List<Data> &list) {
    std::string acc = "";
    list.FoldPreOrder(&StringConcat<Data>,&par,&acc);
    return acc;
}

