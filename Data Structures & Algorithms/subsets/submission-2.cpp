class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx){
        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums, ans, temp, idx + 1);
        temp.pop_back();
        solve(nums, ans, temp, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, ans, temp, 0);

        return ans;
    }
};