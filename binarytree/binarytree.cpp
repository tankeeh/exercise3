
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../TreeUtils/TreeUtilsFunctions.hpp"

/* ************************************************************************** */

// ...



template <typename Data>
bool BinaryTree<Data>::operator==(BinaryTree& tree) const noexcept{
    if(this->size == tree.size){



    }else return false;
}



template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor functor, void *par){
    MapPreOrder(functor,&par,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor functor, void *par){
    MapInOrder(functor,&par,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor functor, void *par){
    MapPostOrder(functor,&par,&this->Root());
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
void BinaryTree<Data>::MapPreOrder(MapFunctor functor, void *par,Node* temp){

        functor(temp->Element(), par);
        if(temp->HasLeftChild()) MapPreOrder(functor, par, &temp->LeftChild());
        if(temp->HasRightChild())MapPreOrder(functor, par, &temp->RightChild());

}

template <typename Data>
void BinaryTree<Data>::PrintTreePreOrder(){
    this->MapPreOrder(&PrintElementTree<Data>, nullptr);
}

template <typename Data>
void BinaryTree<Data>::PrintTreeInOrder(){
    this->MapInOrder(&PrintElementTree<Data>, nullptr);
}

template <typename Data>
void BinaryTree<Data>::PrintTreePostOrder(){
    this->MapPostOrder(&PrintElementTree<Data>, nullptr);
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor functor, void *par,Node* temp){
    if(temp->HasLeftChild()) MapInOrder(functor, par, &temp->LeftChild());
    functor(temp->Element(), par);
    if(temp->HasRightChild())MapInOrder(functor, par, &temp->RightChild());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor functor, void *par,Node* temp){
    if(temp->HasLeftChild()) MapPostOrder(functor, par, &temp->LeftChild());
    if(temp->HasRightChild())MapPostOrder(functor, par, &temp->RightChild());
    functor(temp->Element(), par);
}


//FOLD
template <typename Data>
void BinaryTree<Data>::FoldBreadth(MapFunctor functor, void *par,void* acc,Node* node){}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(MapFunctor functor, void *par,void* acc,Node* node){}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(MapFunctor functor, void *par,void* acc,Node* node){}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(MapFunctor functor, void *par,void* acc,Node* node){}