class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int i = 0;
        int n = intervals.size();

        // // whether newInterval starts after currInt ends
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }

        // check in opp way

        // whether an interval starts on or before the newInt ends
        while (i < n && intervals[i][0] <= newInterval[1]) {
            // Does the next interval start before or at the point where newInterval ends?
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        while (i < n) {
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};