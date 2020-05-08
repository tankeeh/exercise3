
#include "binarytreevec.hpp"

// ...

/** COSTRUTTORI DEL NODO **/

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec(const Data& item,Vector<NodeVec*> *tree){
    this->val = new Data(item);
    this->treevec = tree;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: NodeVec(Data&& item,Vector<NodeVec*> *tree){
    this->val = new Data(std::move(item));
    this->treevec = tree;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec:: ~NodeVec(){
    delete this->val;
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
    Vector<NodeVec*> temp = *(Vector<NodeVec*>*)(this->treevec);
    if(this->curr_index*2 + 1 >= this->treevec->Size()) return false;
    else return ((NodeVec*)temp[(this->curr_index*2)+1] != nullptr);
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    Vector<NodeVec*> temp = *(Vector<NodeVec*>*)(this->treevec);
    if(this->curr_index*2 + 2 >= this->treevec->Size()) return false;
    else return ((NodeVec*)temp[(this->curr_index*2)+2] != nullptr);
}

template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return (this->HasLeftChild() && this->HasRightChild());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasParent() const noexcept{
    Vector<NodeVec*> temp = *(Vector<NodeVec*>*)(this->treevec);
    return ((NodeVec*)temp[(this->curr_index-1)/2] != nullptr && this->curr_index != 0);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftSibling() const noexcept{
    if( this->curr_index != 0 && (this->curr_index%2 != 1)){
        //Vector<NodeVec*> temp = *(Vector<NodeVec*>*)(this->treevec);
        //return ((NodeVec*)temp[this->curr_index-1] != nullptr);
        return (*this->treevec)[this->curr_index - 1] != nullptr;

    }else return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightSibling() const noexcept{
    if( this->curr_index != 0 && (this->curr_index%2 != 0)){
        //Vector<NodeVec*> temp = *(Vector<NodeVec*>*)(this->treevec);
        //return ((NodeVec*)temp[this->curr_index+1] != nullptr);
        return (*this->treevec)[this->curr_index + 1] != nullptr;
    }else return false;
}


template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::Parent() const {
   if(this->HasParent()) {
       Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
       return *(NodeVec*)vett[(this->curr_index-1)/2];
   }
   else throw std::length_error("Tale nodo non ha un genitore.");
}


template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::NodeVec:: LeftSibling() const{
    if(this->HasLeftSibling()) {
        Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
        return *(NodeVec*)vett[this->curr_index-1];
    }
    else throw std::length_error("Tale nodo non ha un fratello sinistro.");
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::NodeVec:: RightSibling() const{
    if(this->HasRightSibling()){
        Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
        return *(NodeVec*)vett[this->curr_index+1];
    }
    else throw std::length_error("Tale nodo non ha un fratello destro.");
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
    if(this->HasLeftChild())return *(NodeVec*)vett[(this->curr_index*2)+1];
    else throw std::out_of_range("Errore. Tentativo di accesso ad un nodo sinistro non presente.");
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {
    Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
    return *(NodeVec*)vett[(this->curr_index*2)+2];
}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
    return *(NodeVec*)vett[(this->curr_index*2)+1];
}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec &BinaryTreeVec<Data>::NodeVec::RightChild() const {
    Vector<NodeVec*> vett = *(Vector<NodeVec*>*)(treevec);
    return *(NodeVec*)vett[(this->curr_index*2)+2];
}


/** FUNCTIONS PER TREEVEC**/








//COPY CONSTRUCTOR TREEVEC ON A GIVEN ROOT DATA
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(const Data& item){
    this->NewRoot(item);
}

//MOVE CONSTRUCTOR TREEVEC ON A GIVEN ROOT DATA
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(Data&& item){
    this->NewRoot(std::move(item));
}

//COPY CONSTRUCTOR
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(const BinaryTreeVec& newtree){
    this->size = newtree.size;
    this->tree.Resize(newtree.tree.Size());

    for(int j=0; j<this->tree.Size();j++){
        if(newtree.tree[j] != nullptr){
            this->tree[j] = new NodeVec(newtree.tree[j]->Element(),&this->tree);
            this->tree[j]->curr_index = j;
        }
        else this->tree[j] = nullptr;
    }

}

//MOVE CONSTRUCTOR
template <typename Data>
BinaryTreeVec<Data>:: BinaryTreeVec(BinaryTreeVec&& newtree){

    std::swap(this->tree,newtree.tree);
    std::swap(this->size,newtree.size);

    for(int i=0;i<this->tree.Size();i++) if(this->tree[i] != nullptr)this->tree[i]->treevec = &this->tree;
}

//COPY ASSIGNMENT
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>:: operator=(const BinaryTreeVec& newtree) noexcept{
    this->Clear();
    this->size = newtree.size;
    this->tree.Resize(newtree.tree.Size());

    for(int j=0; j<this->tree.Size();j++){
        if(newtree.tree[j] != nullptr){
            this->tree[j] = new NodeVec(newtree.tree[j]->Element(),&this->tree);
            this->tree[j]->curr_index = j;
        }
        else this->tree[j] = nullptr;
    }
    return *this;
}

//MOVE ASSIGNMENT
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>:: operator=(BinaryTreeVec&& newtree) noexcept{

    this->Clear();
    std::swap(this->tree,newtree.tree);
    std::swap(this->size,newtree.size);

    for(int i=0;i<this->tree.Size();i++) if(this->tree[i] != nullptr)this->tree[i]->treevec = &this->tree;
    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& tree2) const noexcept{

    if(this->size == tree2.size){
        bool temp = true;
        int i = 0;
        while(i<this->size && temp) {
            if ( this->tree[i]->Element() != tree2.tree[i]->Element() ) temp = false;
            i++;
        }
        return temp;
    }else return false;

}


template <typename Data>
void BinaryTreeVec<Data>::NewRoot(const Data& item) noexcept {
    if(this->tree.Size() == 0) this->tree.Resize(3);
    this->tree[0] = new NodeVec(item,&tree);
    this->size++;
}

template <typename Data>
void BinaryTreeVec<Data>::NewRoot(Data&& item)noexcept {
    if(this->tree.Size() == 0) this->tree.Resize(3);
    this->tree[0] = new NodeVec(std::move(item),&tree);
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
        if((node.curr_index*2 + 1) > tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 1)] = new NodeVec(std::move(item),&tree);
        //this->tree[(node.curr_index*2 + 1)]->treevec = &tree;
        this->tree[(node.curr_index*2 + 1)]->curr_index = node.curr_index*2 + 1;
        this->size++;
    }

}

template<typename Data>
void BinaryTreeVec<Data>::AddLeftChild(BinaryTreeVec::NodeVec &node, const Data &item) noexcept {
    if(this->tree[node.curr_index]->HasLeftChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 1) > tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 1)] = new NodeVec(item,&tree);
        this->tree[(node.curr_index*2 + 1)]->curr_index = node.curr_index*2 + 1;
        this->size++;
    }
}


template<typename Data>
void BinaryTreeVec<Data>::AddRightChild(BinaryTreeVec::NodeVec &node, const Data &item) noexcept {
    if(this->tree[node.curr_index]->HasRightChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) > tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 2)] = new NodeVec(item,&tree);
        this->tree[(node.curr_index*2 + 2)]->curr_index = node.curr_index*2 + 2;
        this->size++;
    }
}


template<typename Data>
void BinaryTreeVec<Data>::AddRightChild(BinaryTreeVec::NodeVec &node,Data&& item) noexcept {
    if(this->tree[node.curr_index]->HasRightChild()){
        return;
    }
    else{
        if((node.curr_index*2 + 2) > tree.Size()) this->Expand();
        this->tree[(node.curr_index*2 + 2)] = new NodeVec(std::move(item),&tree);
        this->tree[(node.curr_index*2 + 2)]->curr_index = node.curr_index*2 + 2;
        this->size++;
    }
}

template <typename Data>
void BinaryTreeVec<Data>:: Expand() noexcept{
this->tree.Resize(this->tree.Size()*2 + 1);

for(int i= 0; i<this->tree.Size();i++){
    if(this->tree[i] != nullptr) this->tree[i]->treevec = &this->tree;
}

}

template <typename Data>
void BinaryTreeVec<Data>:: Reduce() noexcept{
    this->tree.Resize(this->tree.Size()/2);
}

template <typename Data>
void BinaryTreeVec<Data>:: Clear() noexcept{
    for(int j=0;j<this->tree.Size();j++) if(this->tree[j] != nullptr) delete this->tree[j];
    this->tree.Clear();
    this->size = 0;
}

template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor fun ,void* par){

}


template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor fun,const void* par,void* acc) const{

}

