#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class merge_sort {
   public:
    void sort(vector<int>& nums) {
        if (nums.size() < 2) return;
        mergeSort(nums, 0, nums.size() - 1);
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> left(nums.begin() + l, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + r + 1);
        left.push_back(INT_MAX);
        right.push_back(INT_MAX);
        int i = 0;
        int j = 0;
        for (int k = l; k <= r; k++) {
            if (left[i] <= right[j]) {
                nums[k] = left[i];
                i++;
            } else {
                nums[k] = right[j];
                j++;
            }
        }
    }
};

int main() {
    vector<int> nums = {5, 2, 3, 1, 4, 6, 3};
    merge_sort merge;
    merge.sort(nums);
    for (int x : nums) cout << x << " ";  // 1 2 3 3 4 5 6
}