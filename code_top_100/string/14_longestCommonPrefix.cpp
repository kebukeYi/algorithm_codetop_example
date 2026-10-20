#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 编写一个函数来查找字符串数组中的最长公共前缀;
    // strs = ["flower","flow","flight"]; 输出："fl";
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        };
        if (strs.size() == 1) {
            return strs[0];
        };
        string str0 = strs[0];
        // 从左到右
        for (int i = 0; i < str0.size(); i++) {
            // 从上到下
            for (auto str : strs) {
                // 这一列有字母缺失或者不同
                if (i == str0.size() - 1 || str[i] != str0[i]) {
                    // 0 到 j-1 是公共前缀
                    return str0.substr(0, i);
                }
            }
        }
        return "";
    }
};

int main() {}