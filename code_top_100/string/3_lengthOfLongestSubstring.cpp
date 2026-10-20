#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 快慢指针, 相当于滑动窗口; 滑动窗口: 数组, map, set 等数据结构;
    // 什么时机 缩短窗口;
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> map;
        int res = 0;
        int n = s.size();
        //   r
        // abcabd
        // l
        while (right < n) {
            // 扩容窗口;
            char r = s[right];
            right++;
            map[r]++;
            // 尝试缩短窗口;
            while (map[r] > 1) {
                char l = s[left];
                left++;
                if (map[l]) {
                    map[l]--;
                }
            }
            res = max(res, right - left);
        }
        return res;
    }
};

int main() {}