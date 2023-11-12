/**
 * @file bfs_tree_q.h
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief the question set of BFS
 * @version 0.1
 * @date 2023-07-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LEETCODE_C_BFS_Q_H
#define LEETCODE_C_BFS_Q_H

#include "../common_include/c_include.h"

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

/**
 * @brief 94. 二叉树的中序遍历
 * @cite https://leetcode.cn/problems/binary-tree-inorder-traversal/
 *
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize);

/**
 * @brief 104. 二叉树的最大深度
 * @cite https://leetcode.cn/problems/maximum-depth-of-binary-tree/description
 *
 */
int maxDepth(struct TreeNode* root);

/**
 * @brief 111. Minimum Depth of Binary Tree
 * @cite https://leetcode.cn/problems/minimum-depth-of-binary-tree/
 *
 */
int minDepth(struct TreeNode *root);

/**
 * @brief 102. Binary Tree Level Order Traversal
 * @cite https://leetcode.cn/problems/binary-tree-level-order-traversal/
 *
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

#endif