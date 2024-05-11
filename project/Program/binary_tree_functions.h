#ifndef BINARY_TREE_FUNCTIONS_H
#define BINARY_TREE_FUNCTIONS_H

#include <string>

/**
 * @brief Structure representing a node in a binary tree.
 */
struct TreeNode
{
    int val;         /**< Value of the node */
    TreeNode *left;  /**< Pointer to the left child */
    TreeNode *right; /**< Pointer to the right child */

    /**
     * @brief Constructor for TreeNode.
     * @param x Value to assign to the node.
     */
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

namespace BinaryTree
{

    /**
     * @brief Reconstructs a binary tree from a given string.
     *
     * @param str The string containing the serialized binary tree.
     * @return The root node of the reconstructed binary tree.
     */
    TreeNode *reconstructTree(const std::string &str);

    /**
     * @brief Serializes a binary tree into a string.
     *
     * @param root The root node of the binary tree.
     * @return The serialized string representing the binary tree.
     */
    std::string serializeTree(TreeNode *root);

    /**
     * @brief Destroys a binary tree, deallocating memory.
     *
     * @param node The root node of the binary tree.
     */
    void destroyTree(TreeNode *node);

}

#endif // BINARY_TREE_FUNCTIONS_H
