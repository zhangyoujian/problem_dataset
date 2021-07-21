#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

int BinarySearch(int arr[], int N, int target);

int BinarySearchLeftBound(int arr[], int N, int target);

int BinarySearchRightBound(int arr[], int N, int target);

#ifdef __cplusplus
}
#endif

#endif