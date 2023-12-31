/**
 * @file hash_q.h
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief the question set of hash
 * @version 0.1
 * @date 2023-08-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LEETCODE_C_HASH_Q_H
#define LEETCODE_C_HASH_Q_H

#include "../common_include/c_include.h"
#include "../common_include/third_party/uthash.h"

/**
 * @brief 49. 字母异位词分组
 * @cite https://leetcode.cn/problems/group-anagrams
 *
 */
char ***groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes);

/**
 * @brief 128. 最长连续序列
 * @cite https://leetcode.cn/problems/longest-consecutive-sequence
 *
 */
int longestConsecutive(int* nums, int numsSize);

/**
 * @brief 169. 多数元素
 * @cite https://leetcode.cn/problems/majority-element/description/
 *
 */
int majorityElement(int* nums, int numsSize);

/**
 * @brief 239. 滑动窗口最大值
 * @cite https://leetcode.cn/problems/sliding-window-maximum
 *
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize);

/**
 * @brief 560. 和为 K 的子数组
 * @cite https://leetcode.cn/problems/subarray-sum-equals-k
 *
 */
int subarraySum(int* nums, int numsSize, int k);

#endif