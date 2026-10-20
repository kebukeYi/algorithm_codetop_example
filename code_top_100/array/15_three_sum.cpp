#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class ThressSum {
    // 3数之和, 替换成, 遍历数子+ 剩余的2数之和;
    vector<vector<int>> three_sum(vector<int>& nums, int k) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            auto rs = two_sum(nums, i + 1, -nums[i]);
            for (auto s : rs) {
                res.push_back({nums[i], s[0], s[1]});
            }
        }
        return res;
    }

    vector<vector<int>> two_sum(vector<int>& nums, int start, int k) {
        vector<vector<int>> res;
        int i = start;
        int j = nums.size() - 1;

        for (int i = start; i < j; i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            while (i < j && nums[i] + nums[j] > k) {
                j--;
            }

            if (i < j && nums[i] + nums[j] == k) {
                res.push_back({nums[i], nums[j]});
            }
        }
        return res;
    }
};

int main() {}