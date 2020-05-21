//
// Created by Antonio on 10/05/2020.
//


/**NAVIGAZIONE SUI TREELNK**/

template <typename Data>
void intRecursiveLnkNavigate(lasd::BinaryTreeLnk<Data>* tree,typename lasd::BinaryTreeLnk<Data>::NodeLnk* node){

    char scelta = '0';

    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"3. per aggiungere un nodo sinistro \n";
        std::cout<<"4. per aggiungere un nodo destro \n";
        std::cout<<"5. per vedere il dato \n";
        std::cout<<"6. per sovrascrivere il dato \n";
        std::cout<<"7. per rimuovere a sinistra \n";
        std::cout<<"8. per rimuovere a destra \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
        case '1':
            if(node->HasLeftChild()) intRecursiveLnkNavigate(tree,&node->LeftChild());
            else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;

        case '2':
            if(node->HasRightChild()) intRecursiveLnkNavigate(tree,&node->RightChild());
            else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;

            case '3':{
            std::cout<<"aggiunta nodo sinistro...\n";
            if(node->HasLeftChild()) std::cout<<"nodo sinistro gia' presente";
            else tree->AddLeftChild(*node,IntValueGenerator());
            break;
            }
        case '4': {
            std::cout<<"aggiunta nodo destro...\n";
            if (node->HasRightChild()) std::cout<<"nodo destro gia' presente";
            else tree->AddRightChild(*node, IntValueGenerator());
            break;

        }
        case '5': {
            std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
            break;
        }
            case '6': {
                int item;
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                std::cout<<"che valore gli vuoi sovrascrivere? : ";
                std::cin>>item;
                node->Element() = item;
                break;
            }
            case '7': {
                std::cout<<"Rimozione del nodo a sinistra e del relativo sottoalbero...\n";
                if(node->HasLeftChild()) tree->RemoveLeftChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;
            }
            case '8': {
                std::cout<<"Rimozione del nodo a destra e del relativo sottoalbero...\n";
                if(node->HasRightChild()) tree->RemoveRightChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
    }
    }


}


template <typename Data>
void intTreeLnkNavigation(lasd::BinaryTreeLnk<Data>* tree){
    std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    intRecursiveLnkNavigate(tree,&tree->Root());
}




template <typename Data>
void floatRecursiveLnkNavigate(lasd::BinaryTreeLnk<Data>* tree,typename lasd::BinaryTreeLnk<Data>::NodeLnk* node){

    char scelta = '0';

    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"3. per aggiungere un nodo sinistro \n";
        std::cout<<"4. per aggiungere un nodo destro \n";
        std::cout<<"5. per vedere il dato \n";
        std::cout<<"6. per sovrascrivere il dato \n";
        std::cout<<"7. per rimuovere a sinistra \n";
        std::cout<<"8. per rimuovere a destra \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild()) floatRecursiveLnkNavigate(tree,&node->LeftChild());
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;

            case '2':
                if(node->HasRightChild()) floatRecursiveLnkNavigate(tree,&node->RightChild());
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;

            case '3':{
                std::cout<<"aggiunta nodo sinistro...\n";
                if(node->HasLeftChild()) std::cout<<"nodo sinistro gia' presente";
                else tree->AddLeftChild(*node,FloatValueGenerator());
                break;
            }
            case '4': {
                std::cout<<"aggiunta nodo destro...\n";
                if (node->HasRightChild()) std::cout<<"nodo destro gia' presente";
                else tree->AddRightChild(*node, FloatValueGenerator());
                break;

            }
            case '5': {
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                break;
            }
            case '6': {
                float item;
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                std::cout<<"che valore gli vuoi sovrascrivere? : ";
                std::cin>>item;
                node->Element() = item;
                break;
            }
            case '7': {
                std::cout<<"Rimozione del nodo a sinistra e del relativo sottoalbero...\n";
                if(node->HasLeftChild()) tree->RemoveLeftChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;
            }
            case '8': {
                std::cout<<"Rimozione del nodo a destra e del relativo sottoalbero...\n";
                if(node->HasRightChild()) tree->RemoveRightChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void floatTreeLnkNavigation(lasd::BinaryTreeLnk<Data>* tree){
    std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    floatRecursiveLnkNavigate(tree,&tree->Root());
}

template <typename Data>
void stringRecursiveLnkNavigate(lasd::BinaryTreeLnk<Data>* tree,typename lasd::BinaryTreeLnk<Data>::NodeLnk* node){

    char scelta = '0';

    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"3. per aggiungere un nodo sinistro \n";
        std::cout<<"4. per aggiungere un nodo destro \n";
        std::cout<<"5. per vedere il dato \n";
        std::cout<<"6. per sovrascrivere il dato \n";
        std::cout<<"7. per rimuovere a sinistra \n";
        std::cout<<"8. per rimuovere a destra \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild()) stringRecursiveLnkNavigate(tree,&node->LeftChild());
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;

            case '2':
                if(node->HasRightChild()) stringRecursiveLnkNavigate(tree,&node->RightChild());
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;

            case '3':{
                std::cout<<"aggiunta nodo sinistro...\n";
                if(node->HasLeftChild()) std::cout<<"nodo sinistro gia' presente";
                else tree->AddLeftChild(*node,CharValueGenerator());
                break;
            }
            case '4': {
                std::cout<<"aggiunta nodo destro...\n";
                if (node->HasRightChild()) std::cout<<"nodo destro gia' presente";
                else tree->AddRightChild(*node, CharValueGenerator());
                break;

            }
            case '5': {
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                break;
            }
            case '6': {
                std::string item;
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                std::cout<<"che valore gli vuoi sovrascrivere? : ";
                std::cin>>item;
                node->Element() = item;
                break;
            }
            case '7': {
                std::cout<<"Rimozione del nodo a sinistra e del relativo sottoalbero...\n";
                if(node->HasLeftChild()) tree->RemoveLeftChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;
            }
            case '8': {
                std::cout<<"Rimozione del nodo a destra e del relativo sottoalbero...\n";
                if(node->HasRightChild()) tree->RemoveRightChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
                break;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void stringTreeLnkNavigation(lasd::BinaryTreeLnk<Data>* tree){
    std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    stringRecursiveLnkNavigate(tree,&tree->Root());
}

/**NAVIGAZIONE SUI TREEVEC**/


template <typename Data>
void intRecursiveVecNavigate(lasd::BinaryTreeVec<Data>* tree,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    if(!(node->HasParent())) std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo genitore \n";
        std::cout<<"3. per aggiungere un nodo sinistro \n";
        std::cout<<"4. per aggiungere un nodo destro \n";
        std::cout<<"5. per vedere il dato \n";
        std::cout<<"6. per sovrascrivere il dato \n";
        std::cout<<"7. per rimuovere a sinistra \n";
        std::cout<<"8. per rimuovere a destra \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild()) intRecursiveVecNavigate(tree,&node->LeftChild());
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;

            case '2':
                if(node->HasRightChild()) intRecursiveVecNavigate(tree,&node->RightChild());
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            case 'r':
                if(node->HasParent()) intRecursiveVecNavigate(tree,&node->Parent());
                else std::cout<<"Tale nodo non ha un nodo genitore.\n";
                break;

            case '3':{
                std::cout<<"aggiunta nodo sinistro...\n";
                if(node->HasLeftChild()) std::cout<<"nodo sinistro gia' presente";
                else tree->AddLeftChild(*node,IntValueGenerator());
                break;
            }
            case '4': {
                std::cout<<"aggiunta nodo destro...\n";
                if (node->HasRightChild()) std::cout<<"nodo destro gia' presente";
                else tree->AddRightChild(*node, IntValueGenerator());
                break;

            }
            case '5': {
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                break;
            }
            case '6': {
                int item;
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                std::cout<<"che valore gli vuoi sovrascrivere? : ";
                std::cin>>item;
                node->Element() = item;
                break;
            }
            case '7': {
                std::cout<<"Rimozione del nodo a sinistra e del relativo sottoalbero...\n";
                if(node->HasLeftChild()) tree->RemoveLeftChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;
            }
            case '8': {
                std::cout<<"Rimozione del nodo a destra e del relativo sottoalbero...\n";
                if(node->HasRightChild()) tree->RemoveRightChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void intTreeVecNavigation(lasd::BinaryTreeVec<Data>* tree){
    intRecursiveVecNavigate(tree,&tree->Root());
}

template <typename Data>
void floatRecursiveVecNavigate(lasd::BinaryTreeVec<Data>* tree,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    if(!(node->HasParent())) std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo genitore \n";
        std::cout<<"3. per aggiungere un nodo sinistro \n";
        std::cout<<"4. per aggiungere un nodo destro \n";
        std::cout<<"5. per vedere il dato \n";
        std::cout<<"6. per sovrascrivere il dato \n";
        std::cout<<"7. per rimuovere a sinistra \n";
        std::cout<<"8. per rimuovere a destra \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild()) floatRecursiveVecNavigate(tree,&node->LeftChild());
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;

            case '2':
                if(node->HasRightChild()) floatRecursiveVecNavigate(tree,&node->RightChild());
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            case 'r':
                if(node->HasParent()) floatRecursiveVecNavigate(tree,&node->Parent());
                else std::cout<<"Tale nodo non ha un nodo genitore.\n";
                break;

            case '3':{
                std::cout<<"aggiunta nodo sinistro...\n";
                if(node->HasLeftChild()) std::cout<<"nodo sinistro gia' presente";
                else tree->AddLeftChild(*node,FloatValueGenerator());
                break;
            }
            case '4': {
                std::cout<<"aggiunta nodo destro...\n";
                if (node->HasRightChild()) std::cout<<"nodo destro gia' presente";
                else tree->AddRightChild(*node, FloatValueGenerator());
                break;

            }
            case '5': {
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                break;
            }
            case '6': {
                float item;
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                std::cout<<"che valore gli vuoi sovrascrivere? : ";
                std::cin>>item;
                node->Element() = item;
                break;
            }
            case '7': {
                std::cout<<"Rimozione del nodo a sinistra e del relativo sottoalbero...\n";
                if(node->HasLeftChild()) tree->RemoveLeftChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;
            }
            case '8': {
                std::cout<<"Rimozione del nodo a destra e del relativo sottoalbero...\n";
                if(node->HasRightChild()) tree->RemoveRightChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }


}


template <typename Data>
void floatTreeVecNavigation(lasd::BinaryTreeVec<Data>* tree){
    floatRecursiveVecNavigate(tree,&tree->Root());
}




template <typename Data>
void stringRecursiveVecNavigate(lasd::BinaryTreeVec<Data>* tree,typename lasd::BinaryTreeVec<Data>::NodeVec* node){

    char scelta = '0';

    if(!(node->HasParent())) std::cout<<"\n Attualmente sei sulla Root dell' albero \n";
    while(scelta != 'e'){

        std::cout<<"\n1. per spostarsi sul nodo sinistro \n";
        std::cout<<"2. per spostarsi sul nodo destro \n";
        std::cout<<"r. per spostarsi sul nodo genitore \n";
        std::cout<<"3. per aggiungere un nodo sinistro \n";
        std::cout<<"4. per aggiungere un nodo destro \n";
        std::cout<<"5. per vedere il dato \n";
        std::cout<<"6. per sovrascrivere il dato \n";
        std::cout<<"7. per rimuovere a sinistra \n";
        std::cout<<"8. per rimuovere a destra \n";
        std::cout<<"e. per uscire \n";

        std::cout<<"\n\ncosa intendi fare ? \n";
        std::cin>>scelta;

        switch(scelta){
            case '1':
                if(node->HasLeftChild()) stringRecursiveVecNavigate(tree,&node->LeftChild());
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;

            case '2':
                if(node->HasRightChild()) stringRecursiveVecNavigate(tree,&node->RightChild());
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            case 'r':
                if(node->HasParent()) stringRecursiveVecNavigate(tree,&node->Parent());
                else std::cout<<"Tale nodo non ha un nodo genitore.\n";
                break;

            case '3':{
                std::cout<<"aggiunta nodo sinistro...\n";
                if(node->HasLeftChild()) std::cout<<"nodo sinistro gia' presente";
                else tree->AddLeftChild(*node,CharValueGenerator());
                break;
            }
            case '4': {
                std::cout<<"aggiunta nodo destro...\n";
                if (node->HasRightChild()) std::cout<<"nodo destro gia' presente";
                else tree->AddRightChild(*node, CharValueGenerator());
                break;

            }
            case '5': {
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                break;
            }
            case '6': {
                std::string item;
                std::cout<<"il dato del nodo che si sta visitando e' : "<<node->Element()<<"\n";
                std::cout<<"che valore gli vuoi sovrascrivere? : ";
                std::cin>>item;
                node->Element() = item;
                break;
            }
            case '7': {
                std::cout<<"Rimozione del nodo a sinistra e del relativo sottoalbero...\n";
                if(node->HasLeftChild()) tree->RemoveLeftChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero sinistro.\n";
                break;
            }
            case '8': {
                std::cout<<"Rimozione del nodo a destra e del relativo sottoalbero...\n";
                if(node->HasRightChild()) tree->RemoveRightChild(*node);
                else std::cout<<"Tale nodo non ha un sotto albero destro.\n";
                break;
            }
            case 'e':
                std::cout << " Esco dalla navigazione nodi... \n";
                return;
            default:
                std::cout<<"carattere non valido.";
        }
    }

}


template <typename Data>
void stringTreeVecNavigation(lasd::BinaryTreeVec<Data>* tree){
    stringRecursiveVecNavigate(tree,&tree->Root());
}