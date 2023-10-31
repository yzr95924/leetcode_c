/**
 * @file sort_colors.c
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief https://leetcode.cn/problems/sort-colors/description/
 * @version 0.1
 * @date 2023-10-31
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../include/find_sort_q.h"

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void sortColors_75(int* nums, int numsSize)
{
    int headPtr = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            Swap(&nums[headPtr], &nums[i]);
            headPtr++;
        }
    }

    for (int i = headPtr; i < numsSize; i++) {
        if (nums[i] == 1) {
            Swap(&nums[headPtr], &nums[i]);
            headPtr++;
        }
    }
    return;
}
