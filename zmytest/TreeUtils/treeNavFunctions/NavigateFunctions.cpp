//
// Created by Antonio on 10/05/2020.
//


template <typename Data>
void intRecursiveLnkNavigate(lasd::BinaryTreeLnk<Data>* tree,lasd::BinaryTreeLnk<Data>::NodeLnk* node){
    //premi 1 intRecLnkNavigate(tree,&node.LeftChild)
    //premi 2 intRecLnkNavigate(tree,&node.RightChild)
    //premi 3 tree.AddLeft
    //premi 4 tree.AddRight
    //accesso in lettura al dato (element)
    //accesso in scrittura al dato Node.Element() = dato dall'utente
    //rimozione sinistra
    //rimozione destra

    std::coutzz"1. per ";
    std::coutzz"1. per ";
    std::coutzz"1. per ";
    std::coutzz"1. per ";
    std::cout<<"1. per ";
    std::cout<<"1. per ";
    std::cout<<"1. per ";
    std::cout<<"1. per ";

    switch(){
        case '1':
            if(node->HasLeftChild()) intRecursiveLnkNavigate(tree,&node->LeftChild());
        case '2':
            if(node->HasLeftChild()) intRecursiveLnkNavigate(tree,&node->LeftChild());
        case '3':
            if(node->HasLeftChild()) "nodo sinistro gia' presente";
            else tree->AddLeftChild(*node,//valore random);
        case '3':
            if(node->HasLeftChild()) "nodo sinistro gia' presente";
            else tree->AddLeftChild(*node,//valore random);

    }


}


template <typename Data>
void intTreeLnkNavigation(lasd::BinaryTreeLnk<Data>* tree){
    intRecursiveLnkNavigate(tree,&tree->Root());
}