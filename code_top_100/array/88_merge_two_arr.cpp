#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    
    // 合并两个有序数组;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int cut = m + n - 1;
        // 将nums1和nums2中比较大的数，复制到nums1的末尾
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[cut] = nums1[i];
                i--;
                cut--;
            } else {
                nums1[cut] = nums2[j];
                j--;
                cut--;
            }
        }
        // 如果数组2中还有剩余元素，复制到nums1中
        // 如果数组2中没有元素了，但数组1中还有，那无需操作
        while (j >= 0) {
            nums1[cut] = nums2[j];
            j--;
            cut--;
        }
    }
};

int main() {}