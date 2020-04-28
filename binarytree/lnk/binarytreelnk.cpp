
// ...

//costruttore di default ???
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(){
 *this->Node = this->NewRoot(Data());
}


template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk(NodeLnk&& node){

    this->NewRoot(node.Element());
}


//ritorna l'elemento all' interno del nodo (non modificabile)
template <typename Data>
Data BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
    return (*(this->val));
}


//ritorna l'elemento all' interno del nodo (modificabile)
template <typename Data>
Data BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return (*(this->val));

}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NewRoot(Data&& item)noexcept {
this->Node

}