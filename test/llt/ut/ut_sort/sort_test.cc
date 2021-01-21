#include <iostream>
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
using namespace std;
#include "sort.h"



const uint g_bigestNum = 100;
uint N = 0;
int *dataArray = NULL;

void GenerateNums(int *array, uint N)
{
    for (uint i = 0; i < N; ++i) {
        array[i] = rand() % 21 - 10;
    }
}

void PrintData(int *array, uint N) 
{
    for (uint i = 0; i < N; ++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

class test_sort : public testing::Test {
protected:

    static void SetUpTestCase() {
        std::cout<< "TEST_F begin"<<std::endl;
        srand((int)time(0));
        N = rand() % 10 + 1; // generate a number between 1~10
        dataArray = new int[N];
        ASSERT_TRUE(dataArray != NULL);

        GenerateNums(dataArray, N);
    }

    static void TearDownTestCase() {
        if (dataArray != NULL) {
            delete [] dataArray;
        }
        std::cout<< "TEST_F end"<<std::endl;
    }

    virtual void SetUp() {}
    virtual void TearDown() {
        cout<<"origin: "<<endl;
        PrintData(dataArray, N);
    }
private:

};

TEST_F(test_sort, SelectSort)
{
    vector<int> stdResult(dataArray, dataArray + N);
    vector<int> cmpResult(dataArray, dataArray + N);

    sort(stdResult.begin(), stdResult.end(), less<int>());
    SelectSort(cmpResult.data(), cmpResult.size());
    for (uint i = 0; i < N; ++i) {
        EXPECT_EQ(stdResult[i], cmpResult[i]);
    }
    cout<<"std: "<<endl;
    PrintData(stdResult.data(), N);
    cout<<"selectSort: "<<endl;
    PrintData(cmpResult.data(), N);
}

TEST_F(test_sort, BubbleSort)
{
    vector<int> stdResult(dataArray, dataArray + N);
    vector<int> cmpResult(dataArray, dataArray + N);

    sort(stdResult.begin(), stdResult.end(), less<int>());
    BubbleSort(cmpResult.data(), cmpResult.size());
    for (uint i = 0; i < N; ++i) {
        EXPECT_EQ(stdResult[i], cmpResult[i]);
    }
    cout<<"std: "<<endl;
    PrintData(stdResult.data(), N);
    cout<<"BubbleSort: "<<endl;
    PrintData(cmpResult.data(), N);
}

TEST_F(test_sort, InsertSort)
{
    vector<int> stdResult(dataArray, dataArray + N);
    vector<int> cmpResult(dataArray, dataArray + N);

    sort(stdResult.begin(), stdResult.end(), less<int>());
    InsertSort(cmpResult.data(), cmpResult.size());
    for (uint i = 0; i < N; ++i) {
        EXPECT_EQ(stdResult[i], cmpResult[i]);
    }
    cout<<"std: "<<endl;
    PrintData(stdResult.data(), N);
    cout<<"InsertSort: "<<endl;
    PrintData(cmpResult.data(), N);
}

TEST_F(test_sort, ShellSort)
{
    vector<int> stdResult(dataArray, dataArray + N);
    vector<int> cmpResult(dataArray, dataArray + N);

    sort(stdResult.begin(), stdResult.end(), less<int>());
    ShellSort(cmpResult.data(), cmpResult.size());
    for (uint i = 0; i < N; ++i) {
        EXPECT_EQ(stdResult[i], cmpResult[i]);
    }
    cout<<"std: "<<endl;
    PrintData(stdResult.data(), N);
    cout<<"ShellSort: "<<endl;
    PrintData(cmpResult.data(), N);
}

TEST_F(test_sort, MergeSort)
{
    vector<int> stdResult(dataArray, dataArray + N);
    vector<int> cmpResult(dataArray, dataArray + N);

    sort(stdResult.begin(), stdResult.end(), less<int>());
    MergeSort(cmpResult.data(), cmpResult.size());
    for (uint i = 0; i < N; ++i) {
        EXPECT_EQ(stdResult[i], cmpResult[i]);
    }
    cout<<"std: "<<endl;
    PrintData(stdResult.data(), N);
    cout<<"MergeSort: "<<endl;
    PrintData(cmpResult.data(), N);
}

TEST_F(test_sort, HeapSort)
{
    vector<int> stdResult(dataArray, dataArray + N);
    vector<int> cmpResult(dataArray, dataArray + N);

    sort(stdResult.begin(), stdResult.end(), less<int>());
    HeapSort(cmpResult.data(), cmpResult.size());
    for (uint i = 0; i < N; ++i) {
        EXPECT_EQ(stdResult[i], cmpResult[i]);
    }
    cout<<"std: "<<endl;
    PrintData(stdResult.data(), N);
    cout<<"HeapSort: "<<endl;
    PrintData(cmpResult.data(), N);
}

TEST_F(test_sort, QuickSort)
{
    vector<int> stdResult(dataArray, dataArray + N);
    vector<int> cmpResult(dataArray, dataArray + N);

    sort(stdResult.begin(), stdResult.end(), less<int>());
    QuickSort(cmpResult.data(), cmpResult.size());
    for (uint i = 0; i < N; ++i) {
        EXPECT_EQ(stdResult[i], cmpResult[i]);
    }
    cout<<"std: "<<endl;
    PrintData(stdResult.data(), N);
    cout<<"QuickSort: "<<endl;
    PrintData(cmpResult.data(), N);
}