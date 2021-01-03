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


#ifdef __cpluscplus
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
    for (uint j = 0; j < N - 1 -i; ++j) {
        if (arr[j + 1] < arr[j]) {
            int tmp = arr[j];
            arr[j] = arr[j + 1];
            arr[j] = tmp;
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
        uint index = i - 1;
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

    for (uint gap = N / gap; gap > 0; gap /= 2) {
        for (uint i = 0; i < N; i += gap) {
            int insData = arr[i];
            uint index = i - gap;
            while (index >= 0 && insData < arr[index])  {
                arr[index + gap] = arr[index];
                arr[index] = insData;
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
    
    (void)memcpy(leftBuff, arr, leftLength);
    (void)memcpy(rigjhtBuff, arr + leftLength, rightLength);
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

static void HeapUp(int arr[], int i, uint N) 
{
    uint cmpData = arr[i];
    for (uint k = 2 * i + 1; i < N; k = 2 * k + 1) {
        if (k + 1 < N && arr[k] < arr[k + 1]) {
            k++;
        }
        if (arr[k] > cmpData) {
            arr[i] = arr[k];
            i = k;
        }
    }
    arr[i] = cmpData;
}

void HeapSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }

    for (uint i = N/2 - 1; i >= 0; --i) {
        HeapUp(arr, i, N);
    }

    for (uint i = N - 1; i > 0; --i) {
        int tmp = arr[i];
        arr[i] = arr[0];
        arr[0] = tmp;
        HeapUp(arr, 0, i);
    }
}

static void partion( int arr[], uint begin, uint end) 
{
    if (arr == NULL || begin >= end) {
        return;
    }
    uint refIndex = rand() % (end - begin + 1) + begin;
    int refData = arr[refIndex];
    uint index = begin;
    for (uint j = begin; j <= end; ++j) {
        if (arr[j] <= refData) {
            index++;
            if (index != j) {
                int tmp = arr[j];
                arr[j] = arr[index];
                arr[index] = tmp;
            }
        }
    }

    if (index > begin) {
        partion(arr, begin, index);
    }
    if (end > index) {
        partion(arr, index, end);
    }
}

void QuickSort(int arr[], uint N)
{
    if (arr == NULL || N <= 1) {
        return;
    }

    srand(time(NULL));
    partion(arr, 0, N - 1);
}


#ifdef __cplusplus
}
#endif