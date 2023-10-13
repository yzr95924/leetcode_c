/**
 * @file intersection_linked_list.c
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief https://leetcode.cn/problems/intersection-of-two-linked-lists
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../include/linked_list_q.h"

typedef struct ListNode ListNode;
typedef int ZUORU_HashData;

typedef struct {
    void *hashKey;
    ZUORU_HashData hashVal;
    UT_hash_handle hh;
} ZUORU_HashTblPtrItem;

static ZUORU_HashTblPtrItem** ZUORU_InitPtrHashTbl()
{
    ZUORU_HashTblPtrItem **hashTblPtr = (ZUORU_HashTblPtrItem**)calloc(1,
        sizeof(ZUORU_HashTblPtrItem*));
    *hashTblPtr = NULL;
    return hashTblPtr;
}

static void ZUORU_InsertPtrHashTbl(ZUORU_HashTblPtrItem **hashTblPtr,
    void *key, ZUORU_HashData *inVal)
{
    ZUORU_HashTblPtrItem *tmpHashItem = NULL;
    HASH_FIND_PTR(*hashTblPtr, &key, tmpHashItem);
    if (tmpHashItem == NULL) {
        tmpHashItem = (ZUORU_HashTblPtrItem*)calloc(1, sizeof(ZUORU_HashTblPtrItem));
        tmpHashItem->hashKey = key;
        HASH_ADD_PTR(*hashTblPtr, hashKey, tmpHashItem);
    }
    memcpy(&tmpHashItem->hashVal, inVal, sizeof(ZUORU_HashData));
    return;
}

static bool ZUORU_FindPtrHashTbl(ZUORU_HashTblPtrItem **hashTblPtr,
    void *key, ZUORU_HashTblPtrItem **ret)
{
    ZUORU_HashTblPtrItem *tmpHashItem = NULL;
    HASH_FIND_PTR(*hashTblPtr, &key, tmpHashItem);
    if (tmpHashItem == NULL) {
        *ret = NULL;
        return false;
    }

    *ret = tmpHashItem;
    return true;
}

static void ZUORU_FreePtrHashTbl(ZUORU_HashTblPtrItem **hashTblPtr)
{
    ZUORU_HashTblPtrItem *curItem;
    ZUORU_HashTblPtrItem *tmpItem;

    HASH_ITER(hh, *hashTblPtr, curItem, tmpItem) {
        HASH_DEL(*hashTblPtr, curItem);
        free(curItem);
    }
    free(hashTblPtr);
    return;
}

/**
 * @brief 160. 相交链表
 *
 * @param headA
 * @param headB
 * @return struct ListNode*
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    ListNode *retPtr = NULL;
    ZUORU_HashTblPtrItem **hashTblA = ZUORU_InitPtrHashTbl();

    ListNode *APtr = headA;
    ListNode *BPtr = headB;
    int fakeVal = 0;
    while (APtr != NULL) {
        ZUORU_InsertPtrHashTbl(hashTblA, APtr, &fakeVal);
        APtr = APtr->next;
    }

    ZUORU_HashTblPtrItem *tmpFindItm = NULL;
    while (BPtr != NULL) {
        if (ZUORU_FindPtrHashTbl(hashTblA, BPtr, &tmpFindItm)) {
            break;
        }
        BPtr = BPtr->next;
    }

    if (tmpFindItm != NULL) {
        retPtr = tmpFindItm->hashKey;
    }

    ZUORU_FreePtrHashTbl(hashTblA);

    return retPtr;
}
