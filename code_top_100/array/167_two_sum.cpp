#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 不可重复;下标为1开始;
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        int right = n - 1;
        for (int left = 0; left < n; left++) {
            if (left > 0 && nums[left] == nums[left - 1]) {
                continue;
            }
            while (left < right && nums[left] + nums[right] > target) {
                right--;
            }
            if (left < right && nums[left] + nums[right] == target) {
                res.push_back(left + 1);  // 自动扩容;
                res.push_back(right + 1);
                break;
            }
        }
        return res;
    }
};

int main() {}