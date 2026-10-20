#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    
    // 最长连续子序列;
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;
        for (auto x : nums) {
            if (set.contains(x - 1)) {
                continue;
            }
            int y = x + 1;
            while (set.contains(y)) {
                y++;
            }
            ans = max(ans, y - x);
        }
        return ans;
    }
};

int main() {}