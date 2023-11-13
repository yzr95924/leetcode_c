/**
 * @file max_depth_bin_tree.c
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief https://leetcode.cn/problems/maximum-depth-of-binary-tree/description
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../include/bfs_tree_q.h"

#define MY_DATA_STRUCT_EMPTY_POS (-1)
typedef struct TreeNode ZUORU_DataItem;

typedef struct {
    ZUORU_DataItem *data;
    int head;
    int rear;
    int capacity;
    int curSize;
} ZUORU_Queue;

static ZUORU_Queue* ZUORU_InitQueue(int capacity)
{
    ZUORU_Queue *queuePtr = (ZUORU_Queue*)calloc(1, sizeof(ZUORU_Queue));
    queuePtr->data = (ZUORU_DataItem*)calloc(capacity, sizeof(ZUORU_DataItem));
    queuePtr->head = MY_DATA_STRUCT_EMPTY_POS;
    queuePtr->rear = MY_DATA_STRUCT_EMPTY_POS;
    queuePtr->capacity = capacity;
    queuePtr->curSize = 0;

    return queuePtr;
}

static bool ZUORU_EnQueue(ZUORU_Queue *queuePtr, ZUORU_DataItem *inVal)
{
    if (queuePtr->curSize + 1 > queuePtr->capacity) {
        fprintf(stderr, "queue is full\n");
        return false;
    }

    if (queuePtr->head == MY_DATA_STRUCT_EMPTY_POS) {
        queuePtr->head = 0;
    }
    queuePtr->rear = (queuePtr->rear + 1) % queuePtr->capacity;
    memcpy(&queuePtr->data[queuePtr->rear], inVal, sizeof(ZUORU_DataItem));

    queuePtr->curSize++;
    return true;
}

static bool ZUORU_DeQueue(ZUORU_Queue *queuePtr, ZUORU_DataItem *outVal)
{
    if (queuePtr->curSize == 0) {
        fprintf(stderr, "queue is empty\n");
        return false;
    }

    memcpy(outVal, &queuePtr->data[queuePtr->head], sizeof(ZUORU_DataItem));
    if (queuePtr->head == queuePtr->rear) {
        queuePtr->rear = MY_DATA_STRUCT_EMPTY_POS;
        queuePtr->head = MY_DATA_STRUCT_EMPTY_POS;
    }
    queuePtr->head = (queuePtr->head + 1) % queuePtr->capacity;

    queuePtr->curSize--;
    return true;
}

static bool ZUORU_IsEmptyQueue(ZUORU_Queue *queuePtr)
{
    if (queuePtr->curSize == 0) {
        return true;
    }
    return false;
}

static void ZUORU_FreeQueue(ZUORU_Queue *queuePtr)
{
    free(queuePtr->data);
    free(queuePtr);
    return;
}

int maxDepth(struct TreeNode* root)
{
    int ret = 0;
    if (root == NULL) {
        return ret;
    }
    ZUORU_Queue *itemQueue = ZUORU_InitQueue(10000);
    ZUORU_EnQueue(itemQueue, root);
    while (!ZUORU_IsEmptyQueue(itemQueue)) {
        int curQueueSize = itemQueue->curSize;
        while (curQueueSize) {
            struct TreeNode curNode;
            ZUORU_DeQueue(itemQueue, &curNode);
            if (curNode.left != NULL) {
                ZUORU_EnQueue(itemQueue, curNode.left);
            }
            if (curNode.right != NULL) {
                ZUORU_EnQueue(itemQueue, curNode.right);
            }
            curQueueSize--;
        }
        ret++;
    }

    ZUORU_FreeQueue(itemQueue);
    return ret;
}
