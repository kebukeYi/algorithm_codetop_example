#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 两数之和;
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int a = target - nums[i];
            auto it = map.find(a);
            if (it != map.end()) {
                return {it->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }

    
};

int main() {}