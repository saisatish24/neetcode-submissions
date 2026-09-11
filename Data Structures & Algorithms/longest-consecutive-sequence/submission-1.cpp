class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (auto it : st) {
            if (!st.count(it - 1)) {
                int cnt = 1;
                while (st.count(it + 1)) { // while is used bcz there can be more than 1 no. satisfying this condn.
                    cnt++;
                    it++;
                }
                ans = max(ans, cnt);
            }

            
        }
        return ans;
    }
};