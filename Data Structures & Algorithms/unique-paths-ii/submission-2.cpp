class Solution {
public:

    int solve(vector<vector<int>> &dp, int i, int j, int m, int n,               vector<vector<int>>& obstacleGrid){

        if (obstacleGrid[i][j] == 1)
        return 0;
        

        if ( i == (m - 1) && j == (n - 1)){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans  = 0;

        
        if (j + 1 < n)
            ans += solve(dp, i, j + 1, m, n, obstacleGrid);

        if (i + 1 < m)
            ans += solve(dp, i + 1, j, m, n, obstacleGrid);
        
        return dp[i][j] = ans;


    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(dp,0,0,m,n,obstacleGrid);
        
    }
};
