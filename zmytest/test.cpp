

#include <iostream>
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "RandomGens/RandomValues.hpp"
#include "./TreeUtils/TreeUtilsFunctions.hpp"
#include "./TreeUtils/treeNavFunctions/NavigateFunctions.hpp"

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

    //TriplicateIntForBinaryTree(tree2);

    std::cout<<"\nPrint in tutti e 4 i modi : \n";

    PrintElementTreeBreadth(tree2);

    PrintElementTreePreOrder(tree2);

    std::cout<<"\n\n";
    PrintElementTreeInOrder(tree2);

    std::cout<<"\n\n";
    PrintElementTreePostOrder(tree2);
    std::cout<<"\n\n";

    std::cout<<"--- test move constructor ---\n";
    lasd::BinaryTreeLnk<int> tree3(std::move(tree));
    std::cout<<"Print dell' albero che dovrebbe essere vuoto : \n";
    PrintElementTreeBreadth(tree);

    std::cout<<"Print dell' albero che dovrebbe essere pieno (tree3) : \n";
    PrintElementTreeBreadth(tree3);


    std::cout<<"--- test copy assignment ---\n";
    tree = tree2;
    std::cout<<"\nPrint di tree dopo che vi e' stato assegnato tree2: \n";
    PrintElementTreeBreadth(tree);


    std::cout<<"--- test move assignment ---\n";
    tree = std::move(tree2);
    std::cout<<"Print di tree2 dopo essere assegnato con move:\n";
    PrintElementTreeBreadth(tree2);




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

    std::cout<<"\nprint di tree : \n";
    PrintElementTreeBreadth(tree);

    std::cout<<"\nprint di treeUguale : \n";
    PrintElementTreeBreadth(treeUguale);

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
    PrintElementTreeBreadth(tree2);
    std::cout<<"\n\n";
    PrintElementTreePreOrder(tree2);
    std::cout<<"\n\n";
    PrintElementTreeInOrder(tree2);
    std::cout<<"\n\n";
    PrintElementTreeInOrder(tree2);
    std::cout<<"\n\n";

    std::cout<<"--- test move constructor ---\n";
    lasd::BinaryTreeVec<int> tree3(std::move(tree));
    std::cout<<"Print dell' albero che dovrebbe essere vuoto : \n";
    PrintElementTreeBreadth(tree);

    std::cout<<"Print dell' albero che dovrebbe essere pieno (tree3) : \n";
    PrintElementTreeBreadth(tree3);


    std::cout<<"--- test copy assignment ---\n";
    tree = tree2;
    std::cout<<"\nPrint di tree dopo che vi e' stato assegnato tree2: \n";
    PrintElementTreeBreadth(tree);


    std::cout<<"--- test move assignment ---\n";
    tree = std::move(tree2);
    std::cout<<"Print di tree2 dopo essere assegnato con move:\n";
    PrintElementTreeBreadth(tree2);




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
    PrintElementTreeBreadth(tree);

    std::cout<<"\nprint di treeUguale : \n";
    PrintElementTreeBreadth(treeUguale);


    std::cout<<"\ncontrollo uguaglianza tra alberi\n";
    if(tree == treeUguale)std::cout<<"UGUALI\n"; else std::cout<<"DIVERSI\n" ;

    std::cout<<"Risultato della fold per interi : "<<FoldTreeIntMoltiplicateSmallerThan(9,tree);


}


/**BinaryTreeLnk**/


void BinaryTreeLnkInt(){
    char scelta = '0';
    lasd::BinaryTreeLnk<int> albero;

    while(scelta!= 'b' && scelta != '%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. degenere a sinistra. \n";
        std::cout << "d. degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";


        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                albero.AddLeftChild(albero.Root(), IntValueGenerator());
                albero.AddRightChild(albero.Root(), IntValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), IntValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), IntValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), IntValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), IntValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                typename lasd::BinaryTreeLnk<int>::NodeLnk *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, IntValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                typename lasd::BinaryTreeLnk<int>::NodeLnk *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, IntValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }


        while (scelta != 'b') {
            std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeLnk di interi? : \n";
            std::cout << "1. MapBreadth Print. \n";
            std::cout << "2. MapPreOrder Print. \n";
            std::cout << "3. MapInOrder Print. \n";
            std::cout << "4. MapPostOrder Print. \n";
            std::cout << "5. Exists. \n";
            std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";
            std::cout << "7. Map TriplicateInt. \n";
            std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


            std::cout << "b. tornare indietro. \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** BREADTH PRINT ** \n\n";
                    PrintElementTreeBreadth(albero);
                    break;
                case '2':
                    std::cout << " ** PREORDER PRINT ** \n\n";
                    PrintElementTreePreOrder(albero);
                    break;
                case '3':
                    std::cout << " ** INORDER PRINT ** \n\n";
                    PrintElementTreeInOrder(albero);
                    break;
                case '4':
                    std::cout << " ** POSTORDER PRINT ** \n\n";
                    PrintElementTreePostOrder(albero);
                    break;
                case '5':
                    std::cout << " ** EXISTS ** \n\n";
                    std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                    int item;
                    std::cin >> item;
                    if(albero.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                    else std::cout<<"L'elemento e' assente nell' albero";
                    break;
                case '6':
                    std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                    std::cout << "Inserire il valore con cui chiamare la Fold : ";
                    int elem;
                    std::cin >> elem;
                    std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeIntMoltiplicateSmallerThan(elem, albero);
                    break;
                case '7':
                    std::cout << " ** MAP TriplicateInt ** \n\n";
                    TriplicateIntForBinaryTree(albero);
                    break;
                case '8':
                    std::cout << " ** SOTTOTEST NODI ** \n\n";
                    intTreeLnkNavigation(&albero);
                    break;
                case 'b':
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }

            }
    }

void BinaryTreeLnkFloat(){
    char scelta = '0';
    lasd::BinaryTreeLnk<float> albero;

    while(scelta!= 'b' && scelta!='%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. Degenere a sinistra. \n";
        std::cout << "d. Degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";


        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                albero.AddLeftChild(albero.Root(), FloatValueGenerator());
                albero.AddRightChild(albero.Root(), FloatValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), FloatValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), FloatValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), FloatValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), FloatValueGenerator());
                scelta = '%';
                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                typename lasd::BinaryTreeLnk<float>::NodeLnk *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, FloatValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                typename lasd::BinaryTreeLnk<float>::NodeLnk *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, FloatValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
                break;
        }
    }


        while (scelta != 'b') {
            std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeLnk di float? : \n";
            std::cout << "1. MapBreadth Print. \n";
            std::cout << "2. MapPreOrder Print. \n";
            std::cout << "3. MapInOrder Print. \n";
            std::cout << "4. MapPostOrder Print. \n";
            std::cout << "5. Exists. \n";
            std::cout << "6. Fold FloatSumBiggerThan. \n";
            std::cout << "7. Map CubedFloat. \n";
            std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


            std::cout << "b. tornare indietro. \n\n\n";


            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** BREADTH PRINT ** \n\n";
                    PrintElementTreeBreadth(albero);
                    break;
                case '2':
                    std::cout << " ** PREORDER PRINT ** \n\n";
                    PrintElementTreePreOrder(albero);
                    break;
                case '3':
                    std::cout << " ** INORDER PRINT ** \n\n";
                    PrintElementTreeInOrder(albero);
                    break;
                case '4':
                    std::cout << " ** POSTORDER PRINT ** \n\n";
                    PrintElementTreePostOrder(albero);
                    break;
                case '5':
                    std::cout << " ** EXISTS ** \n\n";
                    std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                    float item;
                    std::cin >> item;
                    if(albero.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                    else std::cout<<"L'elemento e' assente nell' albero";
                    break;
                case '6':
                    std::cout << " ** FOLD FloatSumBiggerThan ** \n\n";
                    std::cout << "Inserire il valore con cui chiamare la Fold : ";
                    float elem;
                    std::cin >> elem;
                    std::cout<<"La somma degli elementi maggiori di "<<elem<<" e' :"<<FoldTreeFloatSumBiggerThan(elem, albero);
                    break;
                case '7':
                    std::cout << " ** MAP CubedFloat ** \n\n";
                    CubedFloatForBinaryTree(albero);
                    break;
                case '8':
                    std::cout << " ** SOTTOTEST NODI ** \n\n";
                    floatTreeLnkNavigation(&albero);
                    break;
                case 'b':
                    return;
                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }

        }


}

void BinaryTreeLnkString(){
    char scelta = '0';
    lasd::BinaryTreeLnk<std::string> albero;

    while(scelta!= 'b' && scelta!='%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. Degenere a sinistra. \n";
        std::cout << "d. Degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";



        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                albero.AddLeftChild(albero.Root(), CharValueGenerator());
                albero.AddRightChild(albero.Root(), CharValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), CharValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), CharValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), CharValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), CharValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                typename lasd::BinaryTreeLnk<std::string>::NodeLnk *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, CharValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                typename lasd::BinaryTreeLnk<std::string>::NodeLnk *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, CharValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';

                break;

            }
            case 'b': {
                return;
            }
            default: {
                std::cout << " Hai inserito un codice non valido! riprovare : ";
                break;
            }
        }
    }


        while (scelta != 'b') {
            std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeLnk di stringhe? : \n";
            std::cout << "1. MapBreadth Print. \n";
            std::cout << "2. MapPreOrder Print. \n";
            std::cout << "3. MapInOrder Print. \n";
            std::cout << "4. MapPostOrder Print. \n";
            std::cout << "5. Exists. \n";
            std::cout << "6. Fold StringConcatLowerEqualsThan. \n";
            std::cout << "7. Map InitialConcatString. \n";
            std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


            std::cout << "b. tornare indietro. \n\n\n";


            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** BREADTH PRINT ** \n\n";
                    PrintElementTreeBreadth(albero);
                    break;
                case '2':
                    std::cout << " ** PREORDER PRINT ** \n\n";
                    PrintElementTreePreOrder(albero);
                    break;
                case '3':
                    std::cout << " ** INORDER PRINT ** \n\n";
                    PrintElementTreeInOrder(albero);
                    break;
                case '4':
                    std::cout << " ** POSTORDER PRINT ** \n\n";
                    PrintElementTreePostOrder(albero);
                    break;
                case '5': {
                    std::cout << " ** EXISTS ** \n\n";
                    std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                    std::string item;
                    std::cin >> item;
                    if (albero.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                    else std::cout << "L'elemento e' assente nell' albero";
                    break;
                }
                case '6':{
                    std::cout << " ** FOLD FloatSumBiggerThan ** \n\n";
                    std::cout << "Inserire il valore con cui chiamare la Fold : ";
                    int elem;
                    std::cin >> elem;
                    std::cout << "La concatenazione delle stringhe con lunghezza minore o uguale di " << elem << " e' :"
                              << FoldTreeStringConcatLowerEqualsThan(elem, albero);
                    break;
            }
                case '7': {
                    std::cout << " ** MAP InitialConcatString ** \n\n";
                    std::string par;
                    std::cout << "Che stringa vuoi concatenare all' inizio di ogni stringa?";
                    std::cin >> par;
                    InitialConcatStringForBinaryTree(albero, &par);
                    break;
                }
                case '8':
                    std::cout << " ** SOTTOTEST NODI ** \n\n";
                    stringTreeLnkNavigation(&albero);
                    break;
                case 'b':
                    return;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

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
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}





/**BinaryTreeVec**/


void BinaryTreeVecInt(){
    char scelta = '0';
    lasd::BinaryTreeVec<int> albero;

    while(scelta!= 'b' && scelta != '%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. degenere a sinistra. \n";
        std::cout << "d. degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";



        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                albero.AddLeftChild(albero.Root(), IntValueGenerator());
                albero.AddRightChild(albero.Root(), IntValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), IntValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), IntValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), IntValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), IntValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                typename lasd::BinaryTreeVec<int>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, IntValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(IntValueGenerator());
                typename lasd::BinaryTreeVec<int>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, IntValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }


    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeVec di interi? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold MoltiplicateIntSmallerThan. \n";
        std::cout << "7. Map TriplicateInt. \n";
        std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


        std::cout << "b. tornare indietro. \n\n\n";


        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(albero);
                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(albero);
                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(albero);
                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(albero);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                int item;
                std::cin >> item;
                if(albero.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD MoltiplicateIntSmallerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin >> elem;
                std::cout<<"La moltiplicazione degli elementi minori di "<<elem<<" e' :"<<FoldTreeIntMoltiplicateSmallerThan(elem, albero);
                break;
            case '7':
                std::cout << " ** MAP TriplicateInt ** \n\n";
                TriplicateIntForBinaryTree(albero);
                break;
            case '8':
                std::cout << " ** SOTTOTEST NODI ** \n\n";
                intTreeVecNavigation(&albero);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeVecFloat(){

    char scelta = '0';
    lasd::BinaryTreeVec<float> albero;

    while(scelta!= 'b' && scelta != '%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. degenere a sinistra. \n";
        std::cout << "d. degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";



        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                albero.AddLeftChild(albero.Root(), FloatValueGenerator());
                albero.AddRightChild(albero.Root(), FloatValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), FloatValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), FloatValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), FloatValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), FloatValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                typename lasd::BinaryTreeVec<float>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, FloatValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(FloatValueGenerator());
                typename lasd::BinaryTreeVec<float>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, FloatValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }


    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeVec di float? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold FloatSumBiggerThan. \n";
        std::cout << "7. Map CubedFloat. \n";
        std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


        std::cout << "b. tornare indietro. \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(albero);
                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(albero);
                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(albero);
                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(albero);
                break;
            case '5':
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                float item;
                std::cin >> item;
                if(albero.Exists(item))std::cout<<"L'elemento e' presente nell' albero";
                else std::cout<<"L'elemento e' assente nell' albero";
                break;
            case '6':
                std::cout << " ** FOLD FloatSumBiggerThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                float elem;
                std::cin >> elem;
                std::cout<<"La somma degli elementi maggiori di "<<elem<<" e' :"<<FoldTreeFloatSumBiggerThan(elem, albero);
                break;
            case '7':
                std::cout << " ** MAP CubedFloat ** \n\n";
                CubedFloatForBinaryTree(albero);
                break;
            case '8':
                std::cout << " ** SOTTOTEST NODI ** \n\n";
                floatTreeVecNavigation(&albero);
                break;
            case 'b':
                return;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeVecString(){

    char scelta = '0';
    lasd::BinaryTreeVec<std::string> albero;

    while(scelta!= 'b' && scelta != '%') {
        std::cout << "Che tipo di albero vuoi generare? : \n";
        std::cout << "c. Completo. \n";
        std::cout << "s. degenere a sinistra. \n";
        std::cout << "d. degenere a destra. \n";
        std::cout << "b. tornare indietro. \n";

        std::cin >> scelta;

        switch (scelta) {

            case 'c': {
                std::cout << " ** Generazione albero completo... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                albero.AddLeftChild(albero.Root(), CharValueGenerator());
                albero.AddRightChild(albero.Root(), CharValueGenerator());
                albero.AddLeftChild(albero.Root().LeftChild(), CharValueGenerator());
                albero.AddRightChild(albero.Root().LeftChild(), CharValueGenerator());
                albero.AddLeftChild(albero.Root().RightChild(), CharValueGenerator());
                albero.AddRightChild(albero.Root().RightChild(), CharValueGenerator());
                scelta = '%';

                break;
            }
            case 'd': {
                std::cout << " ** Generazione albero degenere destro... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                typename lasd::BinaryTreeVec<std::string>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddRightChild(*node, CharValueGenerator());
                    node = &node->RightChild();
                    i++;
                }
                scelta = '%';
                break;
            }
            case 's': {
                std::cout << " ** Generazione albero degenere sinistro... ** \n\n";
                albero.NewRoot(CharValueGenerator());
                typename lasd::BinaryTreeVec<std::string>::NodeVec *node = &albero.Root();
                std::cout << "quanti nodi vuoi inserire oltre la root? : ";
                int n;
                int i = 0;
                std::cin >> n;
                while (i < n) {
                    albero.AddLeftChild(*node, CharValueGenerator());
                    node = &node->LeftChild();
                    i++;
                }
                scelta = '%';
                break;

            }
            case 'b':
                std::cout << " Program is gonna stop... \n";
                break;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }


    while (scelta != 'b') {
        std::cout << "\n\nCosa vuoi fare con il seguente BinaryTreeVec di stringhe? : \n";
        std::cout << "1. MapBreadth Print. \n";
        std::cout << "2. MapPreOrder Print. \n";
        std::cout << "3. MapInOrder Print. \n";
        std::cout << "4. MapPostOrder Print. \n";
        std::cout << "5. Exists. \n";
        std::cout << "6. Fold StringConcatLowerEqualsThan. \n";
        std::cout << "7. Map InitialConcatString. \n";
        std::cout << "8. SottoTest: Navigazione sui nodi dell' albero. \n";


        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** BREADTH PRINT ** \n\n";
                PrintElementTreeBreadth(albero);
                break;
            case '2':
                std::cout << " ** PREORDER PRINT ** \n\n";
                PrintElementTreePreOrder(albero);
                break;
            case '3':
                std::cout << " ** INORDER PRINT ** \n\n";
                PrintElementTreeInOrder(albero);
                break;
            case '4':
                std::cout << " ** POSTORDER PRINT ** \n\n";
                PrintElementTreePostOrder(albero);
                break;
            case '5': {
                std::cout << " ** EXISTS ** \n\n";
                std::cout << "Inserire il valore di cui si vuole verificare l'esistenza : ";
                std::string item;
                std::cin >> item;
                if (albero.Exists(item))std::cout << "L'elemento e' presente nell' albero";
                else std::cout << "L'elemento e' assente nell' albero";
                break;
            }
            case '6': {
                std::cout << " ** FOLD StringConcatLowerEqualsThan ** \n\n";
                std::cout << "Inserire il valore con cui chiamare la Fold : ";
                int elem;
                std::cin>>elem;
                std::cout << "\"La concatenazione delle stringhe con lunghezza minore o uguale di \" " << elem<< " e' :" << FoldTreeStringConcatLowerEqualsThan(elem,albero);
                break;
            }
            case '7': {
                std::cout << " ** MAP InitialConcatString ** \n\n";
                std::string par;
                std::cout << "Che stringa vuoi concatenare all' inizio di ogni stringa? : ";
                std::cin >> par;
                InitialConcatStringForBinaryTree(albero, &par);
                break;
            }
            case '8':
                std::cout << " ** SOTTOTEST NODI ** \n\n";
                stringTreeVecNavigation(&albero);
                break;
            case 'b':
                return;
            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}

void BinaryTreeVec(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1. BinaryTreeVec di interi. \n";
        std::cout << "2. BinaryTreeVec di float. \n";
        std::cout << "3. BinaryTreeVec di stringhe. \n";

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
            case 'b':
                return;
            case 'e':
                std::cout << " Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
                break;
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
                std::cout << "Il programma sta per chiudersi... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}








