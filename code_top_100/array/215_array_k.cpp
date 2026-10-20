#include <iostream>
#include <string>
#include <vector>

// https://algorithm-wiki.pages.dev/leetcode/kth-largest-element-in-an-array#%E6%96%B9%E6%B3%95%E4%B8%89-%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F
// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/

// https://www.bilibili.com/video/BV1qP4y1B7kc?spm_id_from=333.788.videopod.sections&vd_source=102f2b2d0254f170289a30c371e91f09
// https://leetcode.cn/problems/kth-largest-element-in-an-array/solutions/2361969/215-shu-zu-zhong-de-di-k-ge-zui-da-yuan-d786p/
using namespace std;

class Solution {
   public:

   //  寻找排序后的数组, 第K位置; O(N)
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    // 超时;
    int quickSelect(vector<int>& nums, int l, int r, int target_index) {
        if (l >= r) return nums[l];
        int p = l + rand() % (r - l + 1);
        swap(nums[p], nums[r]);
        int privot = nums[r];

        // i 的含义是 比 privot 小的元素个数, 正好也是遍历完后要 替换的位置;
        int i = l;
        // j 就是直接递增含义;
        for (size_t j = l; j < r; j++) {
            if (nums[j] < privot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);

        if (i == target_index) {
            return nums[i];
        } else if (i < target_index) {
            return quickSelect(nums, i + 1, r, target_index);
        }
        return quickSelect(nums, l, i - 1, target_index);
    }

    // 三区间计算;
    int quickSelect2(vector<int>& nums, int k) {
        // 基于快排的快速选择
        // 随机选择基准数字
        int p = nums[rand() % nums.size()];
        // 将大于等于小于的元素分别放入三个数组
        vector<int> big, equal, small;
        for (int a : nums) {
            if (a < p)
                small.push_back(a);
            else if (a == p)
                equal.push_back(a);
            else
                big.push_back(a);
        }
        
        // 第k大元素在big中, 递归划分
        if (k <= big.size()) {
            return quickSelect2(big, k);
        }
        // 第k大元素在small中, 递归划分
        if (big.size() + equal.size() < k) {
            return quickSelect2(small, k - (big.size() + equal.size()));
        }
        // 第k大元素在equal中, 返回p
        return p;
    }
};

int main() {
    vector<int> nums = {10, 20, 20, 5, 6, 7, 9, 2, 1};
    Solution so;
    auto re = so.findKthLargest(nums, 2);
    cout << re << endl;
}