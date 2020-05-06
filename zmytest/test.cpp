
//#include "test.hpp"
#include <iostream>
#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "RandomGens/RandomValues.hpp"

/** MY TESTS **/
void TestBinaryTreeLnk(){



    lasd::BinaryTreeLnk<int> tree2;
tree2.NewRoot(6);
tree2.AddLeftChild(tree2.Root(),7);
tree2.AddRightChild(tree2.Root(),8);
tree2.AddLeftChild(tree2.Root().LeftChild(),9);
tree2.AddRightChild(tree2.Root().LeftChild(),10);
tree2.AddLeftChild(tree2.Root().RightChild(),11);
tree2.AddRightChild(tree2.Root().RightChild(),12);


    lasd::BinaryTreeLnk<int> tree(tree2);
    tree2.PrintTreeBreadth();
    std::cout<<"\n\n";
    tree2.PrintTreePreOrder();
    std::cout<<"\n\n";
    tree2.PrintTreeInOrder();
    std::cout<<"\n\n";
    tree2.PrintTreePostOrder();
    std::cout<<"\n\n";

    //tree2.AddRightChild(tree2.Root(),8);



    //  std::cout<<"size del l' albero : "<<tree2.Size()<<std::endl;
//tree2.RemoveLeftChild(tree2.Root());
//std::cout<<"size del l' albero dopo la remove : "<<tree2.Size()<<std::endl;

/*
lasd::BinaryTreeLnk<int>tree(tree2);
std::cout<<"Print di tree : \n";
tree.PrintTreeBreadth();
std::cout<<"\n Print di tree 2 : \n";*/


//tree.PrintTreeInOrder();
//tree.PrintTreePostOrder();
//std::cout<<"Risultato della fold per interi : "<<FoldTreeIntMoltiplicateSmallerThan(9,tree);


}

void TestBinaryTreeVec(){

    lasd::BinaryTreeVec<int> tree;
    tree.NewRoot(5);

    }





/**BinaryTreeLnk**/



void BinaryTreeLnk(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.BinaryTreeLnk di interi. \n";
        std::cout << "2.BinaryTreeLnk di float. \n";
        std::cout << "3.BinaryTreeLnk di string. \n";
        std::cout << "4.BinaryTreeLnk di double. \n";



        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** STACK VETTORE ** \n\n";
                StackVec();
                break;
            case '2':
                std::cout << " ** STACK LISTA ** \n\n";
                StackList();
                break;
            case 'b':
                return;
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        if (scelta != 'e') {
            std::cout << "\n\n Premi un tasto per continuare ...";
            std::cin.get();
        }

    }
}





/**BinaryTreeVec**/


void BinaryTreeVec(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.queue tramite vettore. \n";
        std::cout << "2.queue tramite lista. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** QUEUE VETTORE ** \n\n";
                QueueVec();
                break;
            case '2':
                std::cout << " ** QUEUE LISTA ** \n\n";
                QueueList();
                break;
            case 'b':
                return;
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        if (scelta != 'e') {
            std::cout << "\n\n Premi un tasto per continuare ...";
            std::cin.get();
        }

    }
}




void mytest() {

    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per testare un Albero Binario Lnk. \n";
        std::cout << "2. per testare un Albero Binario Vec. \n";

        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** TEST BinaryTreeLnk ** \n\n";
                BinaryTreeLnk();
                break;
            case '2':
                std::cout << " ** TEST BinaryTreeVec ** \n\n";
                BinaryTreeVec();
                break;
            case 'b':
                return;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        if (scelta != 'e') {
            std::cout << "\n\n Premi un tasto per continuare ...";
            std::cin.get();
        }

    }
}








