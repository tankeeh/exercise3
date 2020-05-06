
#include "binarytreevec.hpp"

// ...

/** COSTRUTTORI DEL NODO **/

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec(const Data& item){
    *this->val = item;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec(Data&& item){
    *this->val = std::move(item);
}


template<typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return (*this->val);
}

template<typename Data>
Data &BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return (*this->val);
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {


    return false;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return false;
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return false;
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {

}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {

    Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
    return *(NodeVec*)vett[(this->curr_index*2)+2];
}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::LeftChild() const {

}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::RightChild() const {

}

template <typename Data>
void BinaryTreeVec<Data>::NewRoot(const Data& item) noexcept {
    this->tree[0] = new NodeVec(item);
    this->tree[0]->treevec = &tree;
    this->size++;
}

template <typename Data>
void BinaryTreeVec<Data>::NewRoot(Data&& item)noexcept {
    this->tree[0] = new NodeVec(std::move(item));
    this->tree[0]->treevec = &tree;
    this->size++;
}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    return *this->tree[0];
}


template<typename Data>
 typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() {
    return *this->tree[0];
}


template<typename Data>
void BinaryTreeVec<Data>::AddLeftChild(BinaryTreeVec::NodeVec &node, Data &&item) noexcept {
    if(this->tree[node.curr_index]->HasLeftChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) >= tree.Size()) tree.Resize(2);
        this->tree[(node.curr_index*2 + 1)] = new NodeVec(std::move(item));
        this->size++;
    }

}

template<typename Data>
void BinaryTreeVec<Data>::AddLeftChild(BinaryTreeVec::NodeVec &node, const Data &item) noexcept {
    if(this->tree[node.curr_index]->HasLeftChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) >= tree.Size()) tree.Resize(2);
        this->tree[(node.curr_index*2 + 1)]->val = item;
        this->size++;
    }
}


template<typename Data>
void BinaryTreeVec<Data>::AddRightChild(BinaryTreeVec::NodeVec &node, const Data &item) noexcept {
    if(this->tree[node.curr_index]->HasRightChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) >= tree.Size()) tree.Resize(2);
        this->tree[(node.curr_index*2 + 2)]->val = std::move(item);
        this->size++;
    }
}


template<typename Data>
void BinaryTreeVec<Data>::AddRightChild(BinaryTreeVec::NodeVec &node,Data&& item) noexcept {
    if(this->tree[node.curr_index]->HasRightChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) >= tree.Size()) tree.Resize(2);
        this->tree[(node.curr_index*2 + 2)]->val = item;
        this->size++;
    }
}