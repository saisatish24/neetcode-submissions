class Solution {
public:

    bool solve(vector<int>& nums, vector<vector<int>>& dp,
           int i, int currSum, int target) {

    if (currSum == target)
        return true;

    if (i >= nums.size())
        return false;

    if (dp[i][currSum] != -1)
        return dp[i][currSum];

    bool include = false;
    bool exclude = false;

    if (currSum + nums[i] <= target) {
        include = solve(nums, dp, i + 1,
                        currSum + nums[i], target);
    }

    exclude = solve(nums, dp, i + 1,
                    currSum, target);

    return dp[i][currSum] = include || exclude;
}

    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        // Odd sum cannot be divided equally among elements
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1)
        );

        return solve(nums, dp, 0, 0, target);
    }
};