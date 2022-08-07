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

#ifdef __cplusplus
extern "C" {
#endif

void SelectSort(int arr[], uint N); // 选择排序
void BubbleSort(int arr[], uint N); // 冒泡排序
void InsertSort(int arr[], uint N); // 插入排序
void ShellSort(int arr[], uint N);  // 希尔排序
void MergeSort(int arr[], uint N);  // 归并排序
void HeapSort(int arr[], uint N);   // 堆排序
void QuickSort(int arr[], uint N);  // 快速排序

void CountSort(int arr[], uint N);  // 计数排序, 待实现...
void BaseSort(int arr[], uint N);  //  基数排序, 待实现...

#ifdef __cplusplus
}
#endif
#endif