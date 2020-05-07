
#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../zmytest/TreeUtils/TreeUtilsFunctions.hpp"

/* ************************************************************************** */

// ...



template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept{
    if(this->size == tree.size){
    //
    }else return false;
}


//MAP
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
void BinaryTree<Data>:: MapBreadth(MapFunctor functor, void *par){
    MapBreadth(functor,&par,&this->Root());
}


//FOLD

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor functor,const void *par,void* acc)const{
    FoldPreOrder(functor,par,acc,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor functor,const void *par,void* acc)const{
    FoldInOrder(functor,par,acc,&this->Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor functor,const void *par,void* acc)const{
    FoldPostOrder(functor,par,acc,&this->Root());
}



template <typename Data>
void BinaryTree<Data>:: FoldBreadth(FoldFunctor functor,const void *par, void* acc)const{
    FoldBreadth(functor,par,acc,&this->Root());
}










/** PROTECTED FUNCTIONS **/


template <typename Data>
void BinaryTree<Data>:: MapBreadth(MapFunctor functor, void *par,Node* node){
    Node* temp = nullptr;
    QueueVec<Node*> queuetemp;
    queuetemp.Enqueue(node);

    while(!(queuetemp.Empty())){
        temp = queuetemp.HeadNDequeue();
        functor(temp->Element(),par);
        if(temp->HasLeftChild())queuetemp.Enqueue(&temp->LeftChild());
        if(temp->HasRightChild())queuetemp.Enqueue(&temp->RightChild());
    }
}




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
void BinaryTree<Data>::PrintTreeBreadth(){
    this->MapBreadth(&PrintElementTree<Data>, nullptr);
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
void MoltiplicateInt(const Data& dat, const void* par, void *acc) {
    if (dat < *(Data*)par){
        *(Data*)acc *= dat;
    }
}

template <typename Data>
Data FoldTreeIntMoltiplicateSmallerThan(const Data& par, BinaryTree<Data> &tree) {
    int acc = 1;
    tree.FoldBreadth(&MoltiplicateInt<Data>,&par,&acc); //&acc ha l'indirizzo di acc locale
    return acc;
}


template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor functor,const void *par,void* acc,const Node* node)const{
    const Node* temp = nullptr;
    QueueVec<const Node*> queuetemp;
    queuetemp.Enqueue(node);

    while(queuetemp.Size() != 0){
        temp = queuetemp.HeadNDequeue();
        functor(temp->Element(),par,acc);
        if(temp->HasLeftChild())queuetemp.Enqueue(&temp->LeftChild());
        if(temp->HasRightChild())queuetemp.Enqueue(&temp->RightChild());
    }
}



template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor functor,const void *par,void* acc,const Node* temp)const{
    functor(temp->Element(), par,acc);
    if(temp->HasLeftChild()) FoldPreOrder(functor, par,acc, &temp->LeftChild());
    if(temp->HasRightChild())FoldPreOrder(functor, par,acc, &temp->RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor functor,const void *par,void* acc,const Node* temp)const{
    if(temp->HasLeftChild()) FoldInOrder(functor, par,acc, &temp->LeftChild());
    functor(temp->Element(), par,acc);
    if(temp->HasRightChild())FoldInOrder(functor, par,acc, &temp->RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor functor,const void *par,void* acc,const Node* temp)const{
    if(temp->HasLeftChild()) FoldPostOrder(functor, par,acc, &temp->LeftChild());
    if(temp->HasRightChild())FoldPostOrder(functor, par,acc, &temp->RightChild());
    functor(temp->Element(), par,acc);
}