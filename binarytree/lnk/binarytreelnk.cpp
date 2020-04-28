
// ...

//costruttore di default ???
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(){
 NodeLnk root = new NodeLnk();
 this->NewRoot(root.Element());

}


template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk(NodeLnk&& node){

    this->NewRoot(node.Element());
}


//ritorna l'elemento all' interno del nodo (non modificabile)
template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const{
    return (*(this->val));
}


//ritorna l'elemento all' interno del nodo (modificabile)
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() {
    return (*(this->val));

}