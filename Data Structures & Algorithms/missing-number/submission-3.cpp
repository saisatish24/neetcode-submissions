class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int Asum = 0;

        for ( int i  = 0; i < n; i++){
            Asum += nums[i];
        }
        
        int Rsum = 0;
        for ( int i = 0; i <= n; i++){
            Rsum += i;
        }

        return Rsum - Asum;


        
    }
};
