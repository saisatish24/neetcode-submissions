class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n);
        vector<int> p(n);
        vector<int> ans(n);

        p[0] = 1;
        s[n - 1] = 1;

        for ( int i = 1; i < n; i++){
            p[i] = nums[i - 1] * p[i - 1];
        }

        for ( int i = n - 2; i >=0; i--){
            s[i] = nums[i + 1] * s[i + 1];
        }

        for( int i = 0;i < n; i++){
            ans[i] = s[i] * p[i];
        }

        return ans;

    }
};
