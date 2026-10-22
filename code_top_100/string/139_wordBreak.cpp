#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    
    // 单词拆分, 单词组合.把 s 划分成若干段,使得每段都在 wordDict 中;
    // 动态规划:假设 在选取e字母下, 剩余的字母的若干段, 是否都在字典中;
    // s = "leetcode", wordDict = ["leet", "code"] true;
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_len = ranges::max(wordDict, {}, &string::size).size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        int n = s.size();
        // 前 n 个字符（整条纸带）→ 这是最终答案 f[n]
        vector<int> f(n + 1);

        f[0] = true;
        // 从 前缀长度 1 开始, 判断这个 长度的 前缀子串能否在字典中;
        for (int i = 1; i <= n; i++) {
            // i 递增, j 只是在 i-- 范围内活动;
            // 再从上面的子串末尾开始递减, 判断其 分段都是否在字典中;
            for (int j = i - 1; j >= 0; j--) {
                // f[j] i前缀前面已经存在 && 再去判断后面的是否存在
                if (f[j] && words.contains(s.substr(j, i - j))) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};

int main() {}