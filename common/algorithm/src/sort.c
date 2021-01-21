/*
Copyright (C), 2020-2050, Tech. Co., Ltd.
File name: sort.c
Author: Youjian zhang
Version: 1.0
Date: 2021.1.2
Description: heard file
*/
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


#ifdef __cplusplus
extern "C" {
#endif

void SelectSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }
    for (uint i = 0; i < N - 1; ++i) 
    for (uint j = i + 1; j < N; ++j) {
        if (arr[j] < arr[i]) {
            int tmp = arr[i];
            arr[i] = arr[j];        
            arr[j] = tmp;
        }
    }
}

void BubbleSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }
    for (uint i = 0; i < N - 1; ++i)
    for (uint j = 0; j < N - 1 - i; ++j) {
        if (arr[j + 1] < arr[j]) {
            int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = tmp;
        }
    }
}

void InsertSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }
    for (uint i = 0; i < N; ++i) {
        int insData = arr[i];
        int index = i - 1;
        while (index >= 0 && insData < arr[index]) {
            arr[index + 1] = arr[index];
            arr[index--] = insData;
        }
    }
}

void ShellSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }

    for (uint gap = N / 2; gap > 0; gap /= 2) {
        for (uint i = 0; i < N; i += gap) {
            int insData = arr[i];
            int index = i - gap;
            while (index >= 0 && insData < arr[index])  {
                arr[index + gap] = arr[index];
                arr[index] = insData;
                index = index - gap;
            }
        }
    }
}

void MergeSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }

    uint leftLength = N / 2;
    uint rightLength = N - leftLength;

    int *leftBuff = (int *)malloc(sizeof(int) * leftLength);
    assert(leftBuff != NULL);
    int *rigjhtBuff = (int *)malloc(sizeof(int) * rightLength);
    assert(rigjhtBuff != NULL);
    
    (void)memcpy(leftBuff, arr, sizeof(int) * leftLength);
    (void)memcpy(rigjhtBuff, arr + leftLength, sizeof(int) * rightLength);
    MergeSort(leftBuff, leftLength);
    MergeSort(rigjhtBuff, rightLength);

    uint left = 0;
    uint right = 0;
    uint index = 0;
    while (left < leftLength && right < rightLength) {
        if (leftBuff[left] < rigjhtBuff[right]) {
            arr[index++] = leftBuff[left++];
        } else {
            arr[index++] = rigjhtBuff[right++];
        }
    }

    while (left < leftLength) {
        arr[index++] = leftBuff[left++];
    }
    while (right < rightLength) {
        arr[index++] = rigjhtBuff[right++];
    }

    free(leftBuff);
    free(rigjhtBuff);
}

static void HeapUp(int arr[], int i, int N) 
{
    int cmpData = arr[i];
    for (uint k = 2 * i + 1; k < N; k = 2 * i + 1) {
        if (k + 1 < N && arr[k] < arr[k + 1]) {
            k++;
        }
        if (arr[k] > cmpData) {
            arr[i] = arr[k];
            i = k;
        } else {
            break;
        }
    }
    arr[i] = cmpData;
}

void HeapSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }

    for (int i = N / 2 - 1; i >= 0; --i) {
        HeapUp(arr, i, N);
    }

    for (int i = N - 1; i > 0; --i) {
        int tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        HeapUp(arr, 0, i);
    }
}

int partion( int arr[], int begin, int end) 
{
    if (arr == NULL || begin >= end) {
        return begin;
    }
    int refIndex = rand() % (end - begin + 1) + begin;
    int tmp = arr[begin];
    arr[begin] = arr[refIndex];
    arr[refIndex] = tmp;

    int index = begin;
    for (int j = begin + 1; j <= end; ++j) {
        if (arr[j] <= arr[begin]) {
            index++;
            if (index != j) {
                int tmp = arr[j];
                arr[j] = arr[index];
                arr[index] = tmp;
            }
        }
    }
    tmp = arr[begin];
    arr[begin] = arr[index];
    arr[index] = tmp;
    return index;
}

void QuickSortCore(int arr[], int left, int right)
{
    int index = partion(arr, left, right);
    if (left < index) {
        QuickSortCore(arr, left, index - 1);
    }
    if (index + 1 < right) {
        QuickSortCore(arr, index + 1, right);
    }
}

void QuickSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }
    srand(time(NULL));
    QuickSortCore(arr, 0, N-1);
}


#ifdef __cplusplus
}
#endif