#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 检测是否是回文串
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {}