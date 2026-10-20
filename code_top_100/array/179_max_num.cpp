#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    
    // 把数组中的元素重新排列组合, 换成string后,是最大值;
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            string s = to_string(a);
            string t = to_string(b);
            return s + t > t + s;
        });

        if (nums[0] == 0) {
            return "0";
        }

        string res;
        for (auto x : nums) {
            res += to_string(x);
        }
        return res;
    }
};

int main() {}