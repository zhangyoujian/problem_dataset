#include <stdio.h>
#include <stdlib.h>

int BinarySearchLower(int* nums, int numsSize, int target)
{
    if (nums == NULL || numsSize < 1) {
        return -1;
    }
    int left = 0;
    int right = numsSize;
    while (left < right) {
        int mid = (right + left)>>1;
        if (nums[mid] == target) { // 下一步向区间 [left, mid)
            right = mid;
        } else if (nums[mid] < target) {   // 下一步 [mid, right]
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left == numsSize) {
        return -1;
    }
    return nums[left] == target ? left : -1;
}

int BinarySearchHigh(int* nums, int numsSize, int target)
{
    if (nums == NULL || numsSize < 1) {
        return -1;
    }
    int left = 0;
    int right = numsSize;
    while (left < right) {
        int mid = (right + left)>>1;
        if (nums[mid] == target) { // 下一步向区间 (mid, right]
            left = mid + 1;
        } else if (nums[mid] < target) {   // 下一步 [mid, right]
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left == 0) {
        return -1;
    }
    return nums[left - 1] == target ? left - 1 : -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ret = (int *)malloc(sizeof(int) * 2);
    int left = BinarySearchLower(nums, numsSize, target);
    if (left == -1) {
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }

    int right = BinarySearchHigh(nums, numsSize, target);
    ret[0] = left;
    ret[1] = right;
    return ret;
}