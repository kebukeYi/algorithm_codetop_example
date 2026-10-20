#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // num1 = "11", num2 = "123"
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        // 从后往前遍历;
        while (i >= 0 || j >= 0 || carry) {
            // 每次重新赋值, 避免沿用;
            int a = (i >= 0) ? num1[i] - '0' : 0;
            int b = (j >= 0) ? num2[j] - '0' : 0;
            int sum = a + b + carry;
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
            i--;
            j--;
        }
        // 直接使用迭代器;
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {}