/**
 * @file single_number.c
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief https://leetcode.cn/problems/single-number/description/
 * @version 0.1
 * @date 2023-10-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../include/math_q.h"

int singleNumber(int *nums, int numsSize)
{
    int ret = 0;
    if (numsSize == 1) {
        return nums[0];
    }

    for (int i = 0; i < numsSize; i++) {
        ret ^= nums[i];
    }

    return ret;
}
