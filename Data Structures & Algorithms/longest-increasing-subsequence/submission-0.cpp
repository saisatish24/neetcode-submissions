class Solution {
public:

    int solver(vector<int>& nums , int curr , int prev , vector<vector<int> > &dp){
        int n = nums.size();
        if ( curr == n){
            return 0;
        } 

        if ( dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
             include = 1 + solver(nums,curr+1,curr,dp);
        }
        
        int exclude = 0 + solver(nums,curr+1,prev,dp);
        

        return dp[curr][prev+1] = max(include,exclude);
    }


    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp (n , vector<int> (n + 1, -1));
        return solver(nums,0,-1,dp);
        
    }
};