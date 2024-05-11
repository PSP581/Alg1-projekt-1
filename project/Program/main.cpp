#include <iostream>
#include "binary_tree_functions.h"

int main()
{
    // Test data
    std::string serializedTree = "(4(2(3)(1))(6(5)))";

    // Reconstructing the binary tree from the serialized string
    TreeNode *root = BinaryTree::reconstructTree(serializedTree);

    // Serializing the reconstructed binary tree
    std::string serializedResult = BinaryTree::serializeTree(root);

    // Outputting the original and serialized strings
    std::cout << "Original Serialized Tree: " << serializedTree << std::endl;
    std::cout << "Reconstructed Serialized Tree: " << serializedResult << std::endl;

    // Memory cleanup
    BinaryTree::destroyTree(root);

    return 0;
}
