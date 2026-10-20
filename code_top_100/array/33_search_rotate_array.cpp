#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 整数数组 nums 按升序排列, 数组中的值 互不相同
    // 1 2 3 4 5 6 target=3 , 在下标3处进行了旋转,找3;
    // 4 5 6 1 2 3
    // O(logN) 解法
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {}