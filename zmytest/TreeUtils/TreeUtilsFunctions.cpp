//
// Created by Antonio on 30/04/2020.
//

template <typename Data>
void PrintElementTree(BinaryTree<Data>& tree){
tree.MapPreOrder(&PrintElement<Data>, nullptr);
}

template <typename Data>
void TriplicateIntForBinaryTree(BinaryTree<Data>& tree){
    tree.MapPreOrder(&TriplicateInt<Data>, nullptr);
}
