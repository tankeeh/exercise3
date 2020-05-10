//
// Created by Antonio on 30/04/2020.
//


template <typename Data>
void PrintElementTreePreOrder(BinaryTree<Data>& tree){
tree.MapPreOrder(&PrintElement<Data>, nullptr);
}

template <typename Data>
void PrintElementTreeBreadth(BinaryTree<Data>& tree){
    tree.MapBreadth(&PrintElement<Data>, nullptr);
}

template <typename Data>
void PrintElementTreeInOrder(BinaryTree<Data>& tree){
    tree.MapInOrder(&PrintElement<Data>, nullptr);
}

template <typename Data>
void PrintElementTreePostOrder(BinaryTree<Data>& tree){
    tree.MapPostOrder(&PrintElement<Data>, nullptr);
}

template <typename Data>
void TriplicateIntForBinaryTree(BinaryTree<Data>& tree){
    tree.MapPreOrder(&TriplicateInt<Data>, nullptr);
}

template <typename Data>
void CubedFloatForBinaryTree(BinaryTree<Data>& tree){
    tree.MapPreOrder(&CubedFloat<Data>, nullptr);
}

template <typename Data>
void InitialConcatStringForBinaryTree(BinaryTree<Data>& tree){
    tree.MapPreOrder(&InitialConcatString<Data>, nullptr);
}



template <typename Data>
Data FoldTreeIntMoltiplicateSmallerThan(const Data& par, BinaryTree<Data> &tree){
    int acc = 1;
    tree.FoldPreOrder(&MoltiplicateInt<Data>,&par,&acc);
    return acc;
}

template <typename Data>
Data FoldTreeFloatSumBiggerThan(const Data& par, BinaryTree<Data> &tree){
    float acc = 0;
    tree.FoldPreOrder(&SumFloatBiggerThan<Data>,&par,&acc);
    return acc;
}

template <typename Data>
Data FoldTreeStringConcatLowerEqualsThan(const Data& par, BinaryTree<Data> &tree){
    std::string acc = "";
    tree.FoldPreOrder(&StringConcat<Data>,&par,&acc);
    return acc;
}


