#include <iostream>
#include <vector>

using namespace std;

class quick_sort {
   public:
    void sort(vector<int>& nums) {
        if (nums.size() < 2) return;
        quickSort(nums, 0, nums.size() - 1);
    }

    int parition(vector<int>& nums, int l, int r) {
        // int piovt = nums[r];  // 超时
        int piovtIndex = l + rand() % (r - l + 1);
        int piovt = nums[piovtIndex];
        swap(nums[piovtIndex], nums[r]);

        int i = l;
        int j = r;
        while (i < j) {
            // 从左到右找到第一个大于等于pivot的元素
            while (i < j && nums[i] < piovt) {
                i++;
            }
            // 从右到左找到第一个小于等于pivot的元素
            while (i < j && nums[j] >= piovt) {
                j--;
            }
            // i到了位置上, j 也到了位置上;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[r]);

        return i;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int p = parition(nums, l, r);
            quickSort(nums, l, p - 1);
            quickSort(nums, p + 1, r);
        }
    };
};

int main() {
    vector<int> nums = {4, 58, 56, 2, 4, 79, 36, 10};
    quick_sort quick;
    quick.sort(nums);
    for (auto x : nums) {
        cout << x << " ";
    }
}