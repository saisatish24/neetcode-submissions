
        class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while ( mid <= high){   // 0s - 0 to low - 1
                                // 1s - low to mid - 1
                                // unsort = mid to high
                                // 2s = high + 1 to n - 1
            if (nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
        
    }
};