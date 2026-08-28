class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }

        int n = height.size();
        int l = 0;
        int r = n - 1;

        int lmax = 0;
        int rmax = 0;

        int ans = 0;

        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (height[l] < height[r]) {
                ans += lmax - height[l++];
            } else {
                ans += rmax - height[r--];
            }
        }
        return ans;
    }
};
