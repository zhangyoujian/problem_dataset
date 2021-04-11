#include <iostream>
#include<vector>
using namespace std;
class Solution_04 {
public:

    double findKposOfSortedArrays(vector<int> nums1, vector<int> nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m < n) {
            return findKposOfSortedArrays(nums2, nums1, k);
        }
        if (nums2.size() == 0) {
            return nums1[k - 1] * 1.0;
        }

        if (k <= 1) {
            return nums1[0] < nums2[0] ?  nums1[0] : nums2[0];
        }

        int mid = k / 2 - 1;
        int left = nums1[mid];
        int right = (mid >= n) ? nums2[n - 1] : nums2[mid];
        if (left <= right) {
            vector<int> temp1(nums1.begin() + mid + 1, nums1.end());
            return findKposOfSortedArrays(temp1, nums2, k - mid - 1);
        }
        int offset = (mid >= n) ? n : mid + 1;
        vector<int> temp2(nums2.begin() + offset, nums2.end());
        return findKposOfSortedArrays(nums1, temp2, k - offset);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int mid = (m + n + 1) / 2;
        if ((m + n) & 0x1) {
            return findKposOfSortedArrays(nums1, nums2, mid);
        } else {
            return (findKposOfSortedArrays(nums1, nums2, mid) + 
                   findKposOfSortedArrays(nums1, nums2, mid + 1)) / 2;
        }
    }
};