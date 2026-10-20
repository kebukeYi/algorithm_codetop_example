#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 给定两个以字符串形式表示的非负整数 num1 和 num2, 返回 num1 和 num2
    // 的乘积，它们的乘积也表示为字符串形式。 字符串相乘;
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);
        for (int i = m - 1; i >= 0; i--) {
            int a = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int b = num2[j] - '0';
                int sum = a * b + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] = sum / 10;
            }
        }

        // 只去除前导0, 中间的 0  不能去除;
        string set;
        for (auto x : res) {
            if (!(set.empty() && x == 0)) {
                set.push_back(x + '0');
            }
        }
        return set;
    }
};

int main() {}