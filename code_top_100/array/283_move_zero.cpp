#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    // 把数组中的 0 元素 都移动到末尾;
    // 输入: nums = [0,1,0,3,12]
    // 0 1 0 3 12
    // 1 0 0 3 12
    // 1 3 0 0 12
    // 1 3 12 0 0
    // 输出: [1,3,12,0,0]
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();

        while (right < n) {
            while (left < n && nums[left] != 0) {
                left++;
            }
            if (right < left) {
                right = left;
            }
            while (right < n && nums[right] == 0) {
                right++;
            }
            if (left < n && right < n) {
                swap(nums[left++], nums[right++]);
            } else {
                break;
            }
        }
    }

    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();

        while (right < n) {
            // 只有在 right 不为0 时, 才去交换;否则 left指针不会移动;
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }

    // 过滤器解法;
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[cnt] = nums[i];
                cnt++;
            }
        }

        while (cnt < nums.size()) {
            nums[cnt] = 0;
            cnt++;
        }
    }
};