
//#include "test.hpp"
#include <iostream>
#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "RandomGens/RandomValues.hpp"
#include "./TreeUtils/TreeUtilsFunctions.hpp"

/** MY TESTS **/
void TestBinaryTreeLnk(){



    lasd::BinaryTreeLnk<int> tree;
    tree.NewRoot(6);
    tree.AddLeftChild(tree.Root(),7);
    tree.AddRightChild(tree.Root(),8);
    tree.AddLeftChild(tree.Root().LeftChild(),9);
    tree.AddRightChild(tree.Root().LeftChild(),10);
    tree.AddLeftChild(tree.Root().RightChild(),11);
    tree.AddRightChild(tree.Root().RightChild(),12);


    std::cout<<"\n--- test copy constructor ---\n";
    lasd::BinaryTreeLnk<int> tree2(tree);

    TriplicateIntForBinaryTree(tree2);

    std::cout<<"\nPrint in tutti e 4 i modi : \n";
    PrintElementTree(tree);
    std::cout<<"\n\n";
    PrintElementTree(tree2);

    tree2.PrintTreePreOrder();
    std::cout<<"\n\n";
    tree2.PrintTreeInOrder();
    std::cout<<"\n\n";
    tree2.PrintTreePostOrder();
    std::cout<<"\n\n";

    std::cout<<"--- test move constructor ---\n";
    lasd::BinaryTreeLnk<int> tree3(std::move(tree));
    std::cout<<"Print dell' albero che dovrebbe essere vuoto : \n";
    tree.PrintTreeBreadth();
    std::cout<<"Print dell' albero che dovrebbe essere pieno (tree3) : \n";
    tree3.PrintTreeBreadth();

    std::cout<<"--- test copy assignment ---\n";
    tree = tree2;
    std::cout<<"\nPrint di tree dopo che vi e' stato assegnato tree2: \n";
    tree.PrintTreeBreadth();

    std::cout<<"--- test move assignment ---\n";
    tree = std::move(tree2);
    std::cout<<"Print di tree2 dopo essere assegnato con move:\n";
    tree2.PrintTreeBreadth();



    std::cout<<"\ncontrollo esistenza dato presente : ";
    if(tree.Exists(7)) std::cout<<"presente"; else std::cout<<"assente";
    std::cout<<"\ncontrollo esistenza dato non presente : ";
    if(tree.Exists(73)) std::cout<<"presente"; else std::cout<<"assente";



    std::cout<<"\nsize del l' albero : \n"<<tree.Size()<<std::endl;
    tree.RemoveLeftChild(tree.Root());
    tree.RemoveRightChild(tree.Root());

    std::cout<<"\nsize del l' albero dopo la remove : "<<tree.Size()<<std::endl;

    lasd::BinaryTreeLnk<int> treeUguale(78);
    std::cout<<"controllo uguaglianza tra alberi\n";
    if(tree == treeUguale)std::cout<<"UGUALI\n"; else std::cout<<"DIVERSI\n" ;
    treeUguale.NewRoot(6);
    std::cout<<"controllo uguaglianza tra alberi\n";
    if(tree == treeUguale)std::cout<<"UGUALI\n"; else std::cout<<"DIVERSI\n" ;

std::cout<<"Risultato della fold per interi : "<<FoldTreeIntMoltiplicateSmallerThan(9,tree);


}

void TestBinaryTreeVec(){
    lasd::BinaryTreeVec<int> tree;
    tree.NewRoot(6);
    tree.AddLeftChild(tree.Root(),7);
    tree.AddRightChild(tree.Root(),8);
    tree.AddLeftChild(tree.Root().LeftChild(),9);
    tree.AddRightChild(tree.Root().LeftChild(),10);
    tree.AddLeftChild(tree.Root().RightChild(),11);
    tree.AddRightChild(tree.Root().RightChild(),12);


    std::cout<<"\n--- test copy constructor ---\n";
    lasd::BinaryTreeVec<int> tree2(tree);

    std::cout<<"\nPrint in tutti e 4 i modi : \n";
    tree2.PrintTreeBreadth();
    std::cout<<"\n\n";
    tree2.PrintTreePreOrder();
    std::cout<<"\n\n";
    tree2.PrintTreeInOrder();
    std::cout<<"\n\n";
    tree2.PrintTreePostOrder();
    std::cout<<"\n\n";

    std::cout<<"--- test move constructor ---\n";
    lasd::BinaryTreeVec<int> tree3(std::move(tree));
    std::cout<<"Print dell' albero che dovrebbe essere vuoto : \n";
    tree.PrintTreeBreadth();
    std::cout<<"Print dell' albero che dovrebbe essere pieno (tree3) : \n";
    tree3.PrintTreeBreadth();

    std::cout<<"--- test copy assignment ---\n";
    tree = tree2;
    std::cout<<"\nPrint di tree dopo che vi e' stato assegnato tree2: \n";
    tree.PrintTreeBreadth();

    std::cout<<"--- test move assignment ---\n";
    tree = std::move(tree2);
    std::cout<<"Print di tree2 dopo essere assegnato con move:\n";
    tree2.PrintTreeBreadth();



    std::cout<<"\ncontrollo esistenza dato presente : ";
    if(tree.Exists(7)) std::cout<<"presente"; else std::cout<<"assente";
    std::cout<<"\ncontrollo esistenza dato non presente : ";
    if(tree.Exists(73)) std::cout<<"presente"; else std::cout<<"assente";



    std::cout<<"\nsize del l' albero : \n"<<tree.Size()<<std::endl;
    tree.RemoveLeftChild(tree.Root());
    tree.RemoveRightChild(tree.Root());

    std::cout<<"\nsize del l' albero dopo la remove : "<<tree.Size()<<std::endl;

    lasd::BinaryTreeVec<int> treeUguale(78);
    std::cout<<"controllo uguaglianza tra alberi\n";
    if(tree == treeUguale)std::cout<<"UGUALI\n"; else std::cout<<"DIVERSI\n" ;
    treeUguale.NewRoot(6);
    std::cout<<"\nprint di tree : \n";
    tree.PrintTreeBreadth();
    std::cout<<"\nprint di treeUguale : \n";
    treeUguale.PrintTreeBreadth();

    std::cout<<"\ncontrollo uguaglianza tra alberi\n";
    if(tree == treeUguale)std::cout<<"UGUALI\n"; else std::cout<<"DIVERSI\n" ;

    std::cout<<"Risultato della fold per interi : "<<FoldTreeIntMoltiplicateSmallerThan(9,tree);


}





/**BinaryTreeLnk**/


void BinaryTreeLnkInt(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeLnk di interi? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";
        std::cout << "7. Map TriplicateInt. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP TriplicateInt ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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
void BinaryTreeLnkFloat(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeLnk di float? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold SumFloatBiggerThan. \n";
        std::cout << "7. Map FloatCube. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD SumFloatBiggerThan ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP FloatCube ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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
void BinaryTreeLnkString(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeLnk di Stringhe? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold ConcatStringSmallerEqualThan. \n";
        std::cout << "7. Map ConcatInitialString. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD ConcatStringSmallerEqualThan. ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP ConcatInitialString. ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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
void BinaryTreeLnkDouble(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeLnk di double? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold SumDoubleBiggerThan. \n";
        std::cout << "7. Map DoubleCube. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD SumDoubleBiggerThan ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP DoubleCube ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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
                std::cout << " ** BINARYTREELNK DI INTERI ** \n\n";
                BinaryTreeLnkInt();
                break;
            case '2':
                std::cout << " ** BINARYTREELNK DI FLOAT ** \n\n";
                BinaryTreeLnkFloat();
                break;
            case '3':
                std::cout << " ** BINARYTREELNK DI STRINGHE ** \n\n";
                BinaryTreeLnkString();
                break;
            case '4':
                std::cout << " ** BINARYTREELNK DI DOUBLE ** \n\n";
                BinaryTreeLnkDouble();
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





/**BinaryTreeVec**/


void BinaryTreeVecInt(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeVec di interi? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";
        std::cout << "7. Map TriplicateInt. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP TriplicateInt ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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
void BinaryTreeVecFloat(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeVec di Float? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold SumFloatBiggerThan. \n";
        std::cout << "7. Map FloatCube. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD SumFloatBiggerThan ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP FloatCube ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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
void BinaryTreeVecString(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeVec di Stringhe? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold ConcatStringSmallerEqualThan. \n";
        std::cout << "7. Map ConcatInitialString. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD ConcatStringSmallerEqualThan. ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP ConcatInitialString. ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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
void BinaryTreeVecDouble(){
    char scelta = '0';

    /* POPOLAMENTO DI UN ALBERO TRAMITE OPPORTUNA FUNZIONE
     * RICORSIVA CHE GENERA IN MODO CASUALE */


    while (scelta != 'e') {
        std::cout << "Cosa vuoi fare con il seguente BinaryTreeVec di double? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold SumDoubleBiggerThan. \n";
        std::cout << "7. Map DoubleCube. \n";
        std::cout << "8. SottoTest: Funzioni comuni sugli alberi. \n";




        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";

                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";

                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";

                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";

                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";

                break;
            case '6':
                std::cout << " ** FOLD SumDoubleBiggerThan ** \n\n";
                break;
            case '7':
                std::cout << " ** MAP DoubleCube ** \n\n";
                break;
            case '8':
                std::cout << " ** SOTTOTEST FUNZIONI COMUNI ** \n\n";
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



void BinaryTreeVec(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1. BinaryTreeVec di interi. \n";
        std::cout << "2. BinaryTreeVec di float. \n";
        std::cout << "2. BinaryTreeVec di stringhe. \n";
        std::cout << "2. BinaryTreeVec di double. \n";


        std::cout<<"\nb. tornare indietro.\n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BINARYTREEVEC DI INTERI ** \n\n";
                BinaryTreeVecInt();
                break;
            case '2':
                std::cout << " ** BINARYTREEVEC DI FLOAT ** \n\n";
                BinaryTreeVecFloat();
                break;
            case '3':
                std::cout << " ** BINARYTREEVEC DI STRINGHE ** \n\n";
                BinaryTreeVecString();
                break;
            case '4':
                std::cout << " ** BINARYTREEVEC DI DOUBLE ** \n\n";
                BinaryTreeVecDouble();
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








