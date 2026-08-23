class Solution {
public:
    int solve(vector<int>& stones, int i, int j, vector<vector<int>>& dp) {
        if (i == j)
            return stones[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeLeft = stones[i] - solve(stones, i + 1, j, dp);
        int takeRight = stones[j] - solve(stones, i, j - 1, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(piles, 0, n - 1, dp) > 0;
    }
};