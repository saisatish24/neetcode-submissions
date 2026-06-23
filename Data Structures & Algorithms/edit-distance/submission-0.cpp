class Solution {
public:

    int solve ( vector<vector<int>> &dp, string &word1 , string &word2, int i , int j){
        if ( i == word1.size()){
            return word2.size() - j;
        }
        if ( j == word2.size()){
            return word1.size() - i;
        }
        
        
        if ( dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if (word1[i] == word2[j]){
            ans += solve(dp,word1,word2,i+1,j+1);
        }
        else{
            ans += min((1 + solve(dp,word1,word2,i+1,j)),min((1 + solve(dp,word1,word2,i,j+1)),(1 + solve(dp,word1,word2,i+1,j+1))));
        }

        return dp[i][j] = ans;
        
    }


    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int> (word2.size() , -1));
        return solve (dp,word1,word2,0,0);
        
    }
};
