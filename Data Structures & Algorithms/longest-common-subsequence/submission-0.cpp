class Solution {
public:

    int solve (int i, int j, vector<vector<int>> &dp , string &text1 , string &text2){
        if ( i == text1.size() || j == text2.size()){
            return 0;
        }

        if ( dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if ( text1[i] == text2[j]){
            ans += 1 + solve(i + 1 ,j + 1,dp,text1,text2);
        }
        else{
            ans += max(solve(i,j+1,dp,text1,text2),solve(i+1,j,dp,text1,text2));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size() , (vector<int> (text2.size(),-1)));
        return solve(0,0,dp,text1,text2);
        
    }
};
