/*
Copyright (C), 2020-2050, Tech. Co., Ltd.
File name: sort.h
Author: Youjian zhang
Version: 1.0
Date: 2021.1.2
Description: heard file
*/
#ifndef SORT_H
#define SORT_H
#include "type.h"

#ifdef __cpluscplus
extern "C" {
#endif

void SelectSort(int arr[], uint N);
void BubbleSort(int arr[], uint N);
void InsertSort(int arr[], uint N);
void ShellSort(int arr[], uint N);
void MergeSort(int arr[], uint N);
void HeapSort(int arr[], uint N);
void QuickSort(int arr[], uint N);


#ifdef __cplusplus
}
#endif
#endif