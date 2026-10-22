#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 最小覆盖子串;
    // 滑动窗口;
    string minWindow(string s, string t) {
        unordered_map<char, int> count;
        unordered_map<char, int> need;
        int left = 0, right = 0, match = 0;
        int start = 0, length = INT_MAX;
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }

        while (right < s.size()) {
            // 扩容窗口
            char c = s[right];
            right++;
            if (need.count(c)) {
                count[c]++;
                if (count[c] == need[c]) {
                    // 字符集合匹配上了, 那就记录;
                    match++;
                }
            }

            // 缩短窗口
            while (match == need.size()) {
                if (right - left < length) {
                    start = left;
                    length = right - left;
                }
                char l = s[left];
                left++;
                // 判断要祛除的字符是否 是 目标字符集
                if (need.count(l)) {
                    // 如果祛除之前, 已经满足匹配了, 那么就破坏匹配;
                    if (count[l] == need[l]) {
                        match--;
                    }
                    count[l]--;
                }
            }
        }

        if (length == INT_MAX) {
            return "";
        }
        // string str(s.begin() + start, s.begin() + start + length);

        return s.substr(start, length);
    }
};

int main() {}