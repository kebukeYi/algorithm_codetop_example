#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    vector<int> searchRange1(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (nums[l] != target) {
            return {-1, -1};
        }
        vector<int> res;
        res.push_back(l);

        r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] >= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        res.push_back(l);
        return res;
    }

    // 第一个和最后一个位置出现的位置;
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        auto l = findFirst(nums, target);
        auto r = findLast(nums, target);
        res.push_back(l);
        res.push_back(r);
        return res;
    }
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main() {}