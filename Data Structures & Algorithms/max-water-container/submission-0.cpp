class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0;
        int r = n - 1;
        int ans = INT_MIN;

        while ( l < r ){
            int mid = l + (r - l)/2;
            ans = max(ans,(min(heights[l],heights[r]) * (r - l))); 
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
        
    }
};
