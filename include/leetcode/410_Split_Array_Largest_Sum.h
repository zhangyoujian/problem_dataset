#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 1001
#define MAX_INT_VAL   0X7FFFFFFF

class Solution_410 {
public:
    int splitArray(vector<int>& nums, int m) {
        (void)memset(cache, -1, sizeof(cache));
        for (int i = 0; i < nums.size(); ++i)
        for (int j = i; j < nums.size(); ++j) {
            sums[i][j] = getSum(nums, i, j);
        }
        return splitArrayInner(nums, 0, m);
    }
protected:

    int getSum(vector<int>& nums, int left, int right)
    {
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            ret += nums[i];
        }
        return ret;
    }

    int splitArrayInner(vector<int>& nums, int index, int m)
    {   
        int &ret = cache[index][m];
        if (ret != -1) {
            return ret;
        }
        if (m == 1) {
            ret = sums[index][nums.size() - 1];
            return ret;
        }
        ret = MAX_INT_VAL;
        for (int i = index + 1; i < nums.size() && ((nums.size() - i) >= (m - 1)); ++i) {
            ret = std::min(ret, std::max(sums[index][i - 1], splitArrayInner(nums, i, m - 1)));
        }
        return ret;
    }
private:
    int cache[MAX_SIZE][MAX_SIZE];
    int sums[MAX_SIZE][MAX_SIZE];
};