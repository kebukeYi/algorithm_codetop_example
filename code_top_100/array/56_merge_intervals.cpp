#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    
    // 合并多个片段
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 我们可以将区间按照左端点升序排列，然后遍历区间进行合并操作;
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {
            if (end < intervals[i][0]) {
                res.push_back({st, end});
                st = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back({st, end});
        return res;
    }
};

int main() {}