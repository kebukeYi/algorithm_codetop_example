#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
    // 把字符数组中的内容进行翻转;
    // 使用双指针, 从两边往中间移动;
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    // 只翻转数组中的元音字母; hello
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
        while (left < right) {
            while (left < right && !vowels.count(s[left])) {
                left++;
            }
            while (left < right && !vowels.count(s[right])) {
                right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main() {}