
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int c = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (prevEnd > intervals[i][0]) {
                c++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else {
                prevEnd = intervals[i][1];
            }
        }

        return c;
    }
};
