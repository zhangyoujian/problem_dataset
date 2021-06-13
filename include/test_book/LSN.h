#include <iostream>
using namespace std;
class Problem_2 {
public:
    int LSN(int arr[], int N) {
        int dp[256] = {0};
        dp[0] = arr[0];
        int len = 1;
        for (int i = 1; i < N; ++i) {
            if (arr[i] > dp[len - 1]) {
                dp[len] = arr[i];
            } else {
                int pos = binary_search(dp, len, arr[i]);
                dp[pos] = arr[i];
            }
        }
    }
private:
    int binary_search(int dp[], int len, int a) {
        int left = 0;
        int right = len - 1;
        while(left < right) {
            int mid = left + (right - left + 1) / 2;
            if (dp[mid] >= a) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};