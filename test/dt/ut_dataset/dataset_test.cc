#include "dataset_pub.h"
#include <string>
#include <iostream>
using namespace std;

TEST_F(test_dataset, Problem_1_test)
{  
    Problem_1 A;
    A.isMatch_simple("781*?", "781");
}

TEST_F(test_dataset, Problem_2_test)
{  
    Problem_2 A;
    int arr[] = {2, 3, 4, 5, 10};
    A.LSN(arr, sizeof(arr) / sizeof(arr[0]));
}

TEST_F(test_dataset, Problem_3_test)
{  
    Problem_3 A;
    A.FindMaxValue(121);
}

TEST_F(test_dataset, DISABLED_Problem_4_test)
{  
    Problem_4 A;
    const char *d = "3 + 2 * 5";
    double res = A.Calculate(d);
    cout << res <<endl;
}