#include "search.h"
#ifdef __cplusplus
extern "C" {
#endif

int BinarySearch(int arr[], int N, int target)
{
    int left  = 0;
    int right = N - 1;
    int ret   = -1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int BinarySearchLeftBound(int arr[], int N, int target)
{
    int left = 0;
    int right = N;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (arr[mid] == target) {
            right = mid;
        } else if (arr[mid] > target) {
            right = mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        }
    }
    // 跳出循环返回的left表示arr中小于target的元素的个数
    if (left == N) {
        return -1;
    }
    return arr[left] == target ? left : -1;
}

int BinarySearchRightBound(int arr[], int N, int target)
{
    int left = 0;
    int right = N;
    while(left < right) {
        int mid = (left + right) >> 1;
        if (arr[mid] == target) {
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid;
        }
    }
    if (right == 0) {
        return -1;
    }
    return arr[right - 1] == target ? right - 1 : -1;
}

#ifdef __cplusplus
}
#endif