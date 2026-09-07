class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        int i = 0;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        while (i < n) {

            if (i + 1 == n || intervals[i][1] < intervals[i + 1][0]) {
                ans.push_back(intervals[i]);
                i++;
            }
            else {
                while (i + 1 < n &&
                       intervals[i][1] >= intervals[i + 1][0]) {

                    intervals[i][1] =
                        max(intervals[i][1], intervals[i + 1][1]);

                    // Don't move away from the merged interval
                    intervals[i + 1][0] = intervals[i][0];
                    intervals[i + 1][1] = intervals[i][1];

                    i++;
                }

                ans.push_back(intervals[i]);
                i++;
            }
        }

        return ans;
    }
};