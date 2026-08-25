class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0;
        int cand2 = 1;
        int cnt1 = 0;
        int cnt2 = 0;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == cand1) {
                cnt1++;
            } else if (nums[i] == cand2) {
                cnt2++;
            } else if (cnt1 == 0) { 
                // if you get a nums which is neither cand1 or cand2 , then check the cand which has 0 frequency , then replace that candidate with the current nums , if none of the cand has 0 freq than decrement the freq of both
                cand1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cand2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == cand1) {
                cnt1++;
            }
            if (nums[i] == cand2) {
                cnt2++;
            }
        }
        if (cnt1 > nums.size() / 3) {
            ans.push_back(cand1);
        }

        if (cnt2 > nums.size() / 3) {
            ans.push_back(cand2);
        }
        return ans;
    }
};