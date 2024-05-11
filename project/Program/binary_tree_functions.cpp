#include "binary_tree_functions.h"
#include <stack>
#include <sstream>

namespace BinaryTree
{
    /**
     * @brief Reconstructs a binary tree from a string representation.
     *
     * This function reconstructs a binary tree from a given string representation. Each node
     * is represented by its value enclosed in parentheses, with its children nodes
     * recursively enclosed in parentheses.
     * @param str The string representation of the binary tree.
     * @return The root node of the reconstructed binary tree.
     */

    TreeNode *reconstructTree(const std::string &str)
    {
        if (str.empty())
        {
            return nullptr;
        }

        std::stack<TreeNode *> nodeStack;
        TreeNode *root = nullptr;
        int i = 0;

        while (i < static_cast<int>(str.length()))
        {
            if (str[i] == '(')
            {
                i++;
                continue;
            }

            if (str[i] == ')')
            {
                nodeStack.pop();
                i++;
                continue;
            }

            int val = 0;
            bool isNegative = false;

            if (str[i] == '-')
            {
                isNegative = true;
                i++;
            }

            while (isdigit(str[i]))
            {
                val = val * 10 + (str[i] - '0');
                i++;
            }

            if (isNegative)
            {
                val = -val;
            }

            TreeNode *newNode = new TreeNode(val);
            if (!nodeStack.empty())
            {
                TreeNode *parent = nodeStack.top();
                if (!parent->left)
                {
                    parent->left = newNode;
                }
                else
                {
                    parent->right = newNode;
                }
            }
            else
            {
                root = newNode;
            }
            nodeStack.push(newNode);
        }

        return root;
    }

    
    /**
     * @brief Serializes a binary tree into a string representation.
     *
     * This function serializes a binary tree into a string representation.
     * Each node is represented by its value enclosed in parentheses, with its
     * children nodes recursively enclosed in parentheses.
     * @param root The root node of the binary tree to be serialized.
     * @return The string representation of the serialized binary tree.
     */

    std::string serializeTree(TreeNode *root)
    {
        if (!root)
        {
            return "()";
        }

        std::stringstream ss;
        ss << "(" << root->val << serializeTree(root->left) << serializeTree(root->right) << ")";

        return ss.str();
    }

    void destroyTree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }

} // End of BinaryTree
