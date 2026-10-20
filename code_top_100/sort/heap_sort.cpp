#include <iostream>
#include <vector>

using namespace std;

class heap_sort {
   public:
    void sort(vector<int>& nums) { heapSort(nums); }

    void heapSort(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return;
        }

        // 1. 建大顶堆：从最后一个非叶子节点开始下沉
        // 决定"处理哪些节点/轮次"
        for (int i = n / 2 - 1; i >= 0; i--) {
            sinDown(nums, i, n);
        }

        // 一个管"轮到谁"，一个管"这个元素沉几层"
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            sinDown(nums, 0, i);
        }
    }

    void sinDown(vector<int>& nums, int i, int n) {
        // 让"一个元素"沿着树往下沉，直到稳定
        while (true) {
            int largest = i;        // 当前节点
            int left = 2 * i + 1;   // 左孩子
            int right = 2 * i + 2;  // 右孩子
            if (left < n && nums[left] > nums[largest]) {
                largest = left;
            }
            if (right < n && nums[right] > nums[largest]) {
                largest = right;
            }
            // 当前节点 > 左右两个孩子;
            if (largest == i) {
                break;
            }
            // 父节点互相交换
            swap(nums[i], nums[largest]);
            i = largest;
        }
    }
};

int main() {
    vector<int> nums = {5, 2, 3, 1, 4, 6, 3};
    heap_sort heap;
    heap.sort(nums);
    for (int x : nums) cout << x << " ";  // 1 2 3 3 4 5 6
}