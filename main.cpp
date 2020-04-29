
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

lasd::BinaryTreeLnk<int> treeLnk;
treeLnk.NewRoot(4);
treeLnk.AddLeftChild(treeLnk.Root(),7);
std::cout<<"stampa della root : "<<treeLnk.Root().LeftChild().Element();


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