class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while ( l < r){
            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r]){ // compare right side only , left side is tricky
                l = mid + 1;
            }
            else{
                r = mid; //  mid can also be the minimum
            }
                    
        }
        return nums[l];
        
    }
};