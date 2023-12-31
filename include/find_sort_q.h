/**
 * @file find_sort_q.h
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief the question set of BFS
 * @version 0.1
 * @date 2023-08-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LEETCODE_C_FIND_SORT_Q_H
#define LEETCODE_C_FIND_SORT_Q_H

#include "../common_include/c_include.h"

/**
 * @brief 33. 搜索旋转排序数组
 * @cite https://leetcode.cn/problems/search-in-rotated-sorted-array
 *
 */
int search_33(int* nums, int numsSize, int target);

/**
 * @brief 34. 在排序数组中查找元素的第一个和最后一个位置
 * @cite https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 */
int* searchRange_34(int* nums, int numsSize, int target, int* returnSize);

/**
 * @brief 35. 搜索插入位置
 * @cite https://leetcode.cn/problems/search-insert-position
 *
 */
int searchInsert_35(int* nums, int numsSize, int target);

/**
 * @brief 56. 合并区间
 * @cite https://leetcode.cn/problems/merge-intervals
 *
 */
int** merge_56(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize,
    int** returnColumnSizes);

/**
 * @brief 74. 搜索二维矩阵
 * @cite https://leetcode.cn/problems/search-a-2d-matrix/
 *
 */
bool searchMatrix_74(int** matrix, int matrixSize, int* matrixColSize, int target);

/**
 * @brief 75. 颜色分类
 * @cite https://leetcode.cn/problems/sort-colors/
 *
 */
void sortColors_75(int* nums, int numsSize);

/**
 * @brief 240. 搜索二维矩阵 II
 * @cite https://leetcode.cn/problems/search-a-2d-matrix-ii/
 *
 */
bool searchMatrix_240(int** matrix, int matrixSize, int* matrixColSize, int target);

#endif