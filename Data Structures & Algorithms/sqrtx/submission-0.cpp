class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        int ans = 0;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (1LL * m * m == x) {
                return m;
            }
            else if (1LL * m * m < x) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        return ans;
    }
};