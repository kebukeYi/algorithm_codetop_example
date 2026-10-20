#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 接水最多的容器, 使用双指针, 什么时机移动指针? 每次计算完后,
    // 移动较小的那个指针
    int maxArea(vector<int>& height) {
        int ret = 0;
        int left = 0;
        int right = height.size()-1;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            ret = max(ret, h * w);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ret;
    }
};

int main() {}