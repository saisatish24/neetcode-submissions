class Solution {
public:

    int solve(vector<int> &dp , int i , int n){

        if (i > n) return 0;
 
        if ( i == n) return 1;
        

        if ( dp[i] != -1){
            return dp[i];
        }
        
        dp[i] = (solve(dp,i + 1,n) + solve(dp,i + 2,n));
        return dp[i];
    
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1,-1);
        return solve(dp,0,n);
        
    }
};
