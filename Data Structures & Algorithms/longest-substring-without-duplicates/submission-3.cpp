class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];

        for (int i = 0; i < 256; i++) {
            hash[i] = -1;
        }

        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {  // if hash[s[r]] is beyond the window , ignore it
                    l = hash[s[r]] + 1;
                }
            }
hash[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            
            r++;
        }
        return maxLen;
    }
};
