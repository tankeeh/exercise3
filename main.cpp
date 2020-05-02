
#include <iostream>
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

#include "./stack/vec/stackvec.hpp"
#include "./queue/lst/queuelst.hpp"
#include "./queue/vec/queuevec.hpp"
#include "./binarytree/lnk/binarytreelnk.hpp"
#include "./binarytree/vec/binarytreevec.hpp"

using namespace lasd;

int main(){

    lasd::BinaryTreeLnk<int> tree2;
tree2.NewRoot(6);
tree2.AddLeftChild(tree2.Root(),7);
tree2.AddRightChild(tree2.Root(),8);
tree2.AddLeftChild(tree2.Root().LeftChild(),9);
tree2.AddRightChild(tree2.Root().LeftChild(),10);
tree2.AddLeftChild(tree2.Root().RightChild(),11);
tree2.AddRightChild(tree2.Root().RightChild(),12);




std::cout<<"size del l' albero : "<<tree2.Size()<<std::endl;
tree2.RemoveLeftChild(tree2.Root());
std::cout<<"size del l' albero dopo la remove : "<<tree2.Size()<<std::endl;

/*
lasd::BinaryTreeLnk<int>tree(tree2);
std::cout<<"Print di tree : \n";
tree.PrintTreeBreadth();
std::cout<<"\n Print di tree 2 : \n";*/

    std::cout<<"\n\n";
tree2.PrintTreeBreadth();
std::cout<<"\n\n";

tree2.PrintTreePreOrder();
//tree.PrintTreeInOrder();
//tree.PrintTreePostOrder();
//std::cout<<"Risultato della fold per interi : "<<FoldTreeIntMoltiplicateSmallerThan(9,tree);

/**MENU' FINALE**/
/*
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "\nPrego, inserire : \n";
        std::cout << "1. Per utilizzare il Test ''ZLASDTEST'' . \n";
        std::cout << "2. Per utilizzare il Test dello studente (ZMYTEST). \n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** ZLASDTEST ** \n\n";
                test();
                break;
            case '2':
                std::cout << " ** ZMYTEST ** \n\n";
                mytest();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }
*/
  return 0;

}

// ...