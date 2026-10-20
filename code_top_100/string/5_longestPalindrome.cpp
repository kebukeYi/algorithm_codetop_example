#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 字符串中的最长回文子串;
    // 之前是从两端往中间走; 换一个思路,中心发散思想, 从中间往两边走;
    // 奇数位 两边扩散; 偶数位两边扩散;
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            string r1 = expend(i, i, s);      // 奇数长度回文
            string r2 = expend(i, i + 1, s);  // 偶数长度回文
            // 直接更新最大值，不需要单独的 Max 函数
            if (r1.length() > res.length()) res = r1;
            if (r2.length() > res.length()) res = r2;
        }
        return res;
    }

    string expend(int left, int right, string& s) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // 长度是 right - left - 1
        return s.substr(left + 1, right - left - 1);
    }
};

int main() {}