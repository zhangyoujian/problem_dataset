#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
问题概述: 
问题详细描述: 
解法:
状态: pass
*/

class Problem_3 {
public:
    int FindMaxValueInner(int start, int currentValue, int remainSize, char *isVisited)
    {
        int ret = currentValue;
        int N = value.size();
        for (int i = start; i < N; ++i) {
            if (isVisited[i] == 0 && weight[i] <= remainSize) {
                isVisited[i] = 1;
                ret = max(ret, FindMaxValueInner(i + 1, currentValue + value[i], remainSize - weight[i], isVisited));
                isVisited[i] = 0;
            }
        }
        return ret;
    }

    int FindMaxValue(int volumn)
    {
        int N = value.size();
        int M = weight.size();
        char *isVisited = new char[N];
        memset(isVisited, 0, sizeof(char) * N);
        int ret = FindMaxValueInner(0, 0, volumn, isVisited);
        delete [] isVisited;
        return ret;
    }

private:
    vector<int> value;
    vector<int> weight;
    int max(int a, int b) {
        return a > b ? a : b;
    }
};