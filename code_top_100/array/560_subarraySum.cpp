#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    
    // 1.前缀和
    // 2.滑动窗口
    // 3.动态规划
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map{{0, 1}};
        int cut = 0, sum = 0;
        for (auto x : nums) {
            sum = sum + x;
            cut = cut + map[sum - k];
            map[sum]++;
        }
        return cut;
    }
};

int main() {}