#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {

    
    string decodeString(string s) {
        stack<char> stk;
        for (auto c : s) {
             // 不是 ']' 就入栈,遇到 ']' 再解码
            if (c != ']') {
                stk.push(c);
                continue;
            }
            // 解码 step 1: 提取本段字符串
            string str;
            while (stk.top() != '[') {
                str = stk.top() + str;
                stk.pop();
            }
             // 移出 '['
            stk.pop();
            // 解码 step 2: 提取本段数字
            int k = 0, base = 1;
            while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9') {
                k = k + (stk.top() - '0') * base;
                base *= 10;
                stk.pop();
            }
            // 本段解码后再次入栈, 以防外层还有数字循环;
            for (int i = 0; i < k; i++) {
                for (auto c : str) {
                    stk.push(c);
                }
            }
        }
         // 出栈拼接（栈顶到栈底是逆序,最后 reverse）
        string res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {}