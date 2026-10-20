#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {

    // 下一个排列; 数组中的数字的下一个字典序的排列, 最小的最大;
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1;
        // 从后往前找  高位 小于 低位的值, 也就说明 还有变大的可能;
        // k-1 < k 的元素位置;
        while (k > 0 && nums[k - 1] >= nums[k]) {
            k--;
        }
        if (k == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // 1 2 4 6 5 3
            // 1 2 5 3 4 6
            // 找到位置后,再从剩下的数字中 找到比 nums[k-1] 更大的最小数字,
            // 进行替换;
            int t = nums.size() - 1;
            while (t > 0 && nums[t] <= nums[k - 1]) {
                t--;
            }
            swap(nums[k - 1], nums[t]);
            reverse(nums.begin()+k, nums.end());
        }
    }
};

int main() {}