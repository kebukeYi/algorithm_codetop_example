#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 给你一个整数数组 nums
    // 请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    // 子数组是数组中的一个连续部分;

    // 前缀和 + 前缀和的最小值;
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1);
        sum[0] = 0;
        // 先算出来前缀和;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        // sum[j] - sum[i] = max, 找出和 sum[i]的最小值;
        // 遍历存在的 前缀和数组;
        vector<int> preMin(n + 1);
        preMin[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            preMin[i] = min(preMin[i - 1], sum[i]);
        }
        int ant = -10000;
        for (int i = 1; i < n + 1; i++) {
            //  preMin[i - 1] 代表着 sum[i-1] 内的 最小值了;
            ant = max(ant, sum[i] - preMin[i - 1]);
        }
        return ant;
    }


    // 动态规划;
    // 设 dp[i] = max(num[i], dp[i-1]+num[i])
    int maxSubArray2(vector<int>& nums) {
        int ans = nums[0];  // 全局最大
        int cur = nums[0];  // 以当前元素结尾的最大子数组和
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};

int main() {}