#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    // 寻找两个数组中的 中位数;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto merge = nums1;
        merge.insert(merge.end(), nums2.begin(), nums2.end());
        ranges::sort(merge);
        int s = merge.size();
        int k = (s - 1) / 2;  // 目标值;
        // int k = (s) / 2;  // 目标值;
        //  5  6
        //  1 2 3 4 5
        //  1 2 3 4 5 6
        return s % 2 ? merge[k] : (merge[k] + merge[k + 1]) / 2.0;
    }
};