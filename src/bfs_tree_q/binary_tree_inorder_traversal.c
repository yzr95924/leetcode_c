/**
 * @file binary_tree_inorder_traversal.c
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief https://leetcode.cn/problems/binary-tree-inorder-traversal/
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../include/bfs_tree_q.h"

#define MAX_TREE_NODE_NUM 100

static void InnerTraversal(struct TreeNode *curNode, int *retArr, int *curRetSize)
{
    if (curNode == NULL) {
        return;
    }
    InnerTraversal(curNode->left, retArr, curRetSize);
    retArr[*curRetSize] = curNode->val;
    (*curRetSize)++;
    InnerTraversal(curNode->right, retArr, curRetSize);
    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int curRetSize = 0;
    int *retArr = (int*)calloc(MAX_TREE_NODE_NUM, sizeof(int));
    InnerTraversal(root, retArr, &curRetSize);
    *returnSize = curRetSize;
    return retArr;
}
