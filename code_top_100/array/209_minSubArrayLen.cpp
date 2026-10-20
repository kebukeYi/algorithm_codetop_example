#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 数组中 连续值等于 target的子序列长度;

    // 2. 滑动窗口, 双指针;
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int n = nums.size();

        long long s = 0;
        int ans = n + 1;
        for (int r = 0; r < n; r++) {
            s = s + nums[r];
            while (s >= target) {
                ans = min(ans, r - l + 1);
                s = s - nums[l];
                l++;
            }
        }
        return ans > n ? 0 : ans;
    }

    // 1. 前缀和, 二分查找;
    int minSubArrayLen2(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(n+1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        // 初始化为一个"比任何可能答案都大"的值
        int ant = n + 1;
        for (int i = 0; i < n; i++) {
            // sum[j] = sum[i] + 中间的差值
            // 在前缀和集合中, 寻找目标位置 = 当前位置 + target;
            int r = lower_bound(sum.begin(), sum.end(), sum[i] + target) -
                    sum.begin();
            if (r <= n) {
                ant = min(ant, r - i);
            }
        }
        return ant <= n ? ant : 0;
    }
};

int main() {}