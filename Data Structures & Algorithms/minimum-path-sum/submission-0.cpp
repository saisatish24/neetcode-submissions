class Solution {
   public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>> & dp) {

        if(i == m - 1 && j == n - 1){
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
     

        if(i < m - 1){
            ans1 = grid[i][j] + solve(grid,i+1,j,m,n,dp);
        }
        if ( j < n - 1){
            ans2 = grid[i][j] + solve(grid,i,j+1,m,n,dp);
        }
       
        return dp[i][j] = min(ans1,ans2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, 0, 0, m, n, dp);
    }
};