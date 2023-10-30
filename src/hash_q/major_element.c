/**
 * @file major_element.c
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief https://leetcode.cn/problems/majority-element/description/
 * @version 0.1
 * @date 2023-10-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../include/hash_q.h"

typedef int ZUORU_HashData;

typedef struct {
    int hashKey;
    ZUORU_HashData hashVal;
    UT_hash_handle hh;
} ZUORU_HashTblIntItem;

static ZUORU_HashTblIntItem** ZUORU_InitIntHashTbl()
{
    ZUORU_HashTblIntItem **hashTblPtr = (ZUORU_HashTblIntItem**)calloc(1,
        sizeof(ZUORU_HashTblIntItem*));
    *hashTblPtr = NULL;
    return hashTblPtr;
}

static ZUORU_HashTblIntItem* ZUORU_InsertIntHashTbl(ZUORU_HashTblIntItem **hashTblPtr,
    int key, ZUORU_HashData *inVal)
{
    ZUORU_HashTblIntItem *tmpHashItem;

    HASH_FIND_INT(*hashTblPtr, &key, tmpHashItem);
    if (tmpHashItem == NULL) {
        tmpHashItem = (ZUORU_HashTblIntItem*)calloc(1, sizeof(ZUORU_HashTblIntItem));
        tmpHashItem->hashKey = key;
        HASH_ADD_INT(*hashTblPtr, hashKey, tmpHashItem);
    }
    memcpy(&tmpHashItem->hashVal, inVal, sizeof(ZUORU_HashData));
    return tmpHashItem;
}

static bool ZUORU_FindIntHashTbl(ZUORU_HashTblIntItem **hashTblPtr,
    int key, ZUORU_HashTblIntItem **ret)
{
    ZUORU_HashTblIntItem *tmpHashItem = NULL;
    HASH_FIND_INT(*hashTblPtr, &key, tmpHashItem);
    if (tmpHashItem == NULL) {
        *ret = NULL;
        return false;
    }

    *ret = tmpHashItem;
    return true;
}

static void ZUORU_FreeIntHashTbl(ZUORU_HashTblIntItem **hashTblPtr)
{
    ZUORU_HashTblIntItem *curItem;
    ZUORU_HashTblIntItem *tmpItem;

    HASH_ITER(hh, *hashTblPtr, curItem, tmpItem) {
        HASH_DEL(*hashTblPtr, curItem);
        free(curItem);
    }
    free(hashTblPtr);
    return;
}

int majorityElement(int* nums, int numsSize)
{
    ZUORU_HashTblIntItem **hashTblPtr = ZUORU_InitIntHashTbl();
    int ret = 0;
    ZUORU_HashTblIntItem *tmpHashItem = NULL;
    ZUORU_HashTblIntItem *curHashItem = NULL;
    ZUORU_HashData tmpData = 0;
    for (int i = 0; i < numsSize; i++) {
        if (ZUORU_FindIntHashTbl(hashTblPtr, nums[i], &tmpHashItem)) {
            tmpHashItem->hashVal++;
        } else {
            tmpData = 1;
            ZUORU_InsertIntHashTbl(hashTblPtr, nums[i], &tmpData);
        }
        tmpHashItem = NULL;
    }

    HASH_ITER(hh, *hashTblPtr, curHashItem, tmpHashItem) {
        if (curHashItem->hashVal > numsSize / 2) {
            ret = curHashItem->hashKey;
            break;
        }
    }

    ZUORU_FreeIntHashTbl(hashTblPtr);
    return ret;
}
