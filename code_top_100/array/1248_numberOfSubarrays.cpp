#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    // 存在k个奇数子数组的数目;
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1);
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + (nums[i] % 2);
        }
        vector<long long> count(n+1);
        int ant = 0;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] - k >= 0) {
                ant = ant + count[sum[i] - k];
            }
            count[sum[i]]++;
        }
        return ant;
    }
};

int main() {}