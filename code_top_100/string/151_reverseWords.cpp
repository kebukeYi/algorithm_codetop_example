#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    // 给你一个字符串 s ，请你反转字符串中 单词 的顺序
    string reverseWords(string& s) {
        int m = s.size() - 1;
        string res;
        while (m >= 0 && s[m] == ' ') {
            m--;
        }
        int n = m;
        while (m >= 0) {
            while (m >= 0 && s[m] != ' ') {
                m--;
            }
            res += s.substr(m + 1, n - m)+" ";
            while (m >= 0 && s[m] == ' ') {
                m--;
            }
            n = m;
        }
        if (res.empty()) return "";  // 如果原字符串全是空格，直接返回空
        return res.substr(0, res.size() - 1);  // 忽略最后一位的空格
    }
};

int main() {
    Solution s;
    string a = "the sky";
    auto res = s.reverseWords(a);
    cout << res << endl;
}