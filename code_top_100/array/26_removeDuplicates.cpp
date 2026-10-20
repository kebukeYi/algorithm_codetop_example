#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 过滤器: filter(nums) -> if(condition) -> new_nums;

    // 祛除数组中的重复元素, 并保持相对顺序;
    int removeDuplicates(vector<int>& nums) {
        int cut = 0;  // 新数组的下标;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[cut] = nums[i];
                cut++;
            }
        }
        return cut;
    }
};

int main() {}