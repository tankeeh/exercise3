
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

// ...



template <typename Data>
bool BinaryTree<Data>::operator==(BinaryTree& tree) const noexcept{
    if(this->size == tree.size){



    }else return false
}



template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor functor, void *par){

}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor functor, void *par){

}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor functor,const void *par,void* acc)const{

}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor functor,const void *par,void* acc)const{

}

template <typename Data>
void BinaryTree<Data>:: MapBreadth(MapFunctor functor, void *par){}

template <typename Data>
void BinaryTree<Data>:: FoldBreadth(MapFunctor functor, void *par, void* acc){

}










/** PROTECTED FUNCTIONS **/

//MAP

template <typename Data>
void BinaryTree<Data>:: MapBreadth(MapFunctor functor, void *par,Node* node){}

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor functor, void *par,Node* node){}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor functor, void *par,Node* node){}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor functor, void *par,Node* node){}


//FOLD
template <typename Data>
void BinaryTree<Data>::FoldBreadth(MapFunctor functor, void *par,void* acc,Node* node){}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(MapFunctor functor, void *par,void* acc,Node* node){}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(MapFunctor functor, void *par,void* acc,Node* node){}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(MapFunctor functor, void *par,void* acc,Node* node){}