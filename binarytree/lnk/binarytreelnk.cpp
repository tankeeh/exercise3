
// ...

/*
template <typename Data>
void BinaryTreeLnk<Data>:: TreeAssignment(BinaryTreeLnk<Data>& tree1,BinaryTreeLnk<Data>& tree2){
    NodeLnk nodetemp1 = tree1.Node;
    NodeLnk nodetemp2 = tree2.Node;


}
*/

//costruttore di default ???
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(NodeLnk& node){
this->NewRoot(node.Element());
}


template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk(NodeLnk&& node){
    this->NewRoot(std::move(node.Element()));
}

template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk(BinaryTreeLnk& tree){
this->Node = tree.node;
}

//ritorna l'elemento all' interno del nodo (non modificabile)
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
    return (*(this->val));
}


//ritorna l'elemento all' interno del nodo (modificabile)
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return (*(this->val));

}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::Root() const{
    return (*(this->Node));
}


template <typename Data>
void BinaryTreeLnk<Data>::NewRoot(const Data& item) noexcept {
    this->Node = new NodeLnk(item);
}

template <typename Data>
void BinaryTreeLnk<Data>::NewRoot(Data&& item)noexcept {
    this->Node = new NodeLnk(std::move(item));
}

template <typename Data>
void BinaryTreeLnk<Data>::AddLeftChild(NodeLnk& node,const Data& item)  {
    if(!node.HasLeftChild()){
        node.sx = new NodeLnk(item);
        this->size++;
    }
    else throw std::domain_error("E' gia' presente un nodo sinistro.");
}

template <typename Data>
void BinaryTreeLnk<Data>::AddLeftChild(NodeLnk& node,Data&& item)  {
    if(!node.HasLeftChild()){
    node.sx = new NodeLnk(std::move(item));
    this->size++;
    }
    else throw std::domain_error("E' gia' presente un nodo sinistro.");
}

template <typename Data>
void BinaryTreeLnk<Data>::AddRightChild(NodeLnk& node,const Data& item)  {
    if(!node.HasRightChild()) {
        node.dx = new NodeLnk(item);
        this->size++;
    }else throw std::domain_error("E' gia' presente un nodo destro.");

    }

template <typename Data>
void BinaryTreeLnk<Data>::AddRightChild(NodeLnk& node,Data&& item)  {
    if(!node.HasRightChild()) {
    node.dx = new NodeLnk(std::move(item));
    this->size++;
    }else throw std::domain_error("E' gia' presente un nodo destro.");

}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& item){
    this->val = new Data(item);
    this->sx = nullptr;
    this->dx = nullptr;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& item){
    this->val = new Data(std::move(item));
    this->sx = nullptr;
    this->dx = nullptr;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk &  BinaryTreeLnk<Data>::NodeLnk:: LeftChild()const{
    if(this->sx != nullptr){
        return *this->sx;
    }
    else throw std::out_of_range("Non e' presente un nodo sinistro");
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk &  BinaryTreeLnk<Data>::NodeLnk:: RightChild()const{
    if(this->dx != nullptr){
        return *this->dx;
    }
    else throw std::out_of_range("Non e' presente un nodo destro");
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
    return this->sx == nullptr && this->dx == nullptr;
}

template <typename Data>
bool  BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
    return this->sx != nullptr;
}

template <typename Data>
bool  BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
    return this->dx != nullptr;
}

template <typename Data>
void BinaryTreeLnk<Data>:: Clear(){
    return;
}