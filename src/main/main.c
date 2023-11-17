/**
 * @file main.c
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief the main process
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../../common_include/my_log.h"
#include "../../common_include/my_util.h"
#include "../../common_include/define_const.h"
#include "../../include/app_sys_q.h"
#include "../../include/bfs_tree_q.h"
#include "../../include/math_q.h"
#include "../../include/stack_q.h"
#include "../../include/hash_q.h"
#include "../../include/slide_two_q.h"
#include "../../include/str_arr_q.h"
#include "../../include/greedy_dp_q.h"
#include "../../include/back_track_q.h"
#include "../../include/linked_list_q.h"

#include "../../common_include/c_my_vector.h"

#define MODULE_ID "LeetCodeMain"

int main(int argc, char* argv[]) {
    Vector *gVector = VectorInit(100);

    VectorDataItem tmpItem;
    tmpItem.key = 2; tmpItem.value = 3;
    VectorPushBack(gVector, &tmpItem);
    tmpItem.key = 2; tmpItem.value = 2;
    VectorPushBack(gVector, &tmpItem);
    tmpItem.key = 1; tmpItem.value = 3;
    VectorPushBack(gVector, &tmpItem);
    tmpItem.key = 0; tmpItem.value = 4;
    VectorPushBack(gVector, &tmpItem);
    tmpItem.key = 3; tmpItem.value = 4;
    VectorPushBack(gVector, &tmpItem);
    tmpItem.key = 9; tmpItem.value = 4;
    VectorPushBack(gVector, &tmpItem);

    for (int idx = 0; idx < gVector->size; idx++) {
        ZUORU_LOGGING(INFO_LOG_LEVEL, "key: %d. val: %d\n",
            gVector->data[idx].key, gVector->data[idx].value);
    }

    VectorSortByKeyValue(gVector);

    ZUORU_LOGGING(INFO_LOG_LEVEL, "After sort:\n");
    for (int idx = 0; idx < gVector->size; idx++) {
        ZUORU_LOGGING(INFO_LOG_LEVEL, "key: %d. val: %d\n",
            gVector->data[idx].key, gVector->data[idx].value);
    }

    VectorDel(gVector, 9);
    ZUORU_LOGGING(INFO_LOG_LEVEL, "After del:\n");
    for (int idx = 0; idx < gVector->size; idx++) {
        ZUORU_LOGGING(INFO_LOG_LEVEL, "key: %d. val: %d\n",
            gVector->data[idx].key, gVector->data[idx].value);
    }

    VectorFree(gVector);
    return 0;
}