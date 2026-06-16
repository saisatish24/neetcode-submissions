class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int sr = 0;
        int er = m - 1;
        int sc = 0;
        int ec = n - 1;

        int i = 0;
        int j = 0;

        while ( sr <= er && sc <= ec ){

            for ( int i = sc; i <= ec; i++){
                 ans.push_back(matrix[sr][i]);
            }

            for ( int i = sr + 1; i <= er; i++){
                 ans.push_back(matrix[i][ec]);
            }


            if ( sr < er){
            for ( int i = ec - 1; i >= sc; i--){
                 ans.push_back(matrix[er][i]);
            }
            }

            if (sc < ec){
            for ( int i = er - 1; i >= sr + 1; i--){
                 ans.push_back(matrix[i][sc]);
            }
            }


            sr++;
            er--;
            sc++;
            ec--;
        }
        return ans;
        
    }
};
