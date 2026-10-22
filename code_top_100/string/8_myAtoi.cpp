#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    // 把字符串转为 数字;  -123 +123 0-2 456hello 1320xofe
    // 先祛除空格
    // 然后 判断 + - 符号
    // 然后再 依次 *10 递增 num
    /*
    比如把字符串 123 转换成数字 123，我们可以:
    初始化 num=0
    读取字符 1，把 num 更新成 num⋅10+1=1
    读取字符 2，把 num 更新成 num⋅10+2=10+2=12
    读取字符 3，把 num 更新成 num⋅10+3=120+3=123
    */
    int myAtoi(string s) {
        int n = s.size();
        int cur = 0;
        while (cur < n && s[cur] == '0') {
            cur++;
        }

        int sgin = 1;
        if (cur < n && (s[cur] == '+' || s[cur] == '-')) {
            sgin = s[cur] == '+' ? 1 : -1;
            cur++;
        }
        int num = 0;
        while (cur < n && (s[cur] >= '0' && s[cur] <= '9')) {
            int d = s[cur] - '0';

            if (num > INT_MAX / 10 || num * 10 + d > INT_MAX) {
                return sgin > 0 ? INT_MAX : INT_MIN;
            }
            num = 10 * num + d;
        }
        return sgin * num;
    }
};

int main() {}