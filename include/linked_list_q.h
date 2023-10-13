/**
 * @file linked_list_q.h
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief the question set of linked_list
 * @version 0.1
 * @date 2023-10-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LEETCODE_C_LINKED_LIST_Q_H
#define LEETCODE_C_LINKED_LIST_Q_H

#include "../common_include/c_include.h"
#include "../common_include/third_party/uthash.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * @brief 160. 相交链表
 *
 * @param headA
 * @param headB
 * @return struct ListNode*
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

#endif
