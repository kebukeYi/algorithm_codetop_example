#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 寻找峰值;
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                // nums[mid] <= nums[mid + 1]
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {}