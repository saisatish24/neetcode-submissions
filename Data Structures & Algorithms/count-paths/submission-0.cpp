class Solution {
public:

    int solve(vector<vector<int>> &dp, int i, int j, int m, int n){
        

        if ( i == (m - 1) && j == (n - 1)){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans  = 0;
        if (j + 1 < n)
            ans += solve(dp, i, j + 1, m, n);

        if (i + 1 < m)
            ans += solve(dp, i + 1, j, m, n);
        return dp[i][j] = ans;


    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(dp,0,0,m,n);
        
    }
};
