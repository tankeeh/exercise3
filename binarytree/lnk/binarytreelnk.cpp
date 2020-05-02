
// ...


template <typename Data>
int FoldDiscendentCount(const Data&, const void* par,void* acc){
    *(int*)acc +=1;
    return *(int*)acc;
}





//costruttore di default ???
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(Data& item){
this->NewRoot(item);
}


template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk(Data&& item){
    this->NewRoot(std::move(item));
}


template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk(BinaryTreeLnk& tree){
    this->Node = new NodeLnk(*tree.Node);
}

template <typename Data>
BinaryTreeLnk<Data>:: BinaryTreeLnk(BinaryTreeLnk&& tree){
    std::swap(this->Node,tree.Node);
    std::swap(this->size,tree.size);
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>:: operator=(BinaryTreeLnk& tree)const noexcept {
    Clear();
    this->Node = new NodeLnk(*tree.Node);
    this->size = tree.size;
    return *this;
}


template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>:: operator=(BinaryTreeLnk&& tree) noexcept {
    Clear();
    std::swap(this->Node,tree.Node);
    std::swap(this->size,tree.size);
    return *this;
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
    this->size++;
}

template <typename Data>
void BinaryTreeLnk<Data>::NewRoot(Data&& item)noexcept {
    this->Node = new NodeLnk(std::move(item));
    this->size++;
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

//DISTRUTTORE RICORSIVO RICHIAMATO DALL' INTERNO DEL DISTRUTTORE DELL' ALBERO
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
    if(this->HasLeftChild()) delete this->sx;
    if(this->HasRightChild()) delete this->dx;
    delete this->val;
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
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk& node){
    this->val = new Data(*node.val);
    if(node.sx != nullptr) this->sx = new NodeLnk(*node.sx);
    if(node.dx != nullptr) this->dx = new NodeLnk(*node.dx);
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
    return (this->sx == nullptr && this->dx == nullptr);
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
void BinaryTreeLnk<Data>:: RemoveLeftChild(NodeLnk& node) noexcept{
    if(node.HasLeftChild()){
        int acc = 0;
        delete node.sx;
        node.sx = nullptr;
        this->FoldBreadth(FoldDiscendentCount<Data>, nullptr,&acc);
        this->size = acc;
    }

}

template <typename Data>
void BinaryTreeLnk<Data>:: Clear(){
    delete this->Node;
    this->size = 0;
}