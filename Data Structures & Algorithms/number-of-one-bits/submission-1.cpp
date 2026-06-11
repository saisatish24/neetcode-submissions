class Solution {
public:
    int hammingWeight(uint32_t n) {

        string ans = bitset<32>(n).to_string();
        int count = 0;

        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '1') {
                count++;
            }
        }

        return count;
    }
};
