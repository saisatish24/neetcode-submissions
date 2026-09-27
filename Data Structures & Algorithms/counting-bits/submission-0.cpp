class Solution {
public:

int bin(int i){

    string bin = "";

    while(i > 0) {
        bin += (i % 2) + '0';
        i /= 2;
    }
int count = 0;
    for ( int j = 0; j < bin.size(); j++){
        if( bin[j] == '1') count++;
    }
    return count;
}


    vector<int> countBits(int n) {

        vector<int> ans(n+1);

        for ( int i = 0; i <= n; i++){
            ans[i] = bin(i);
        }

        return ans;
        
    }
};
