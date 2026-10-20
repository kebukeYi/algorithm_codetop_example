#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1);
        for (auto b1 : bookings) {
            diff[b1[0] - 1] += b1[2];
            diff[b1[1] - 1 + 1] -= b1[2];
        }

        // 对 diff 求前缀和;
        vector<int> sum(n + 1);
        sum[0] = 0;
        for (int i = 1; i < n+1; i++) {
            sum[i] = sum[i - 1] + diff[i - 1];
        }
        sum.erase(sum.begin());
        return sum;
    }
};

int main() {}