class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> RowMinimum(n, INT_MAX);
        vector<int> colMaximum(m, INT_MIN);
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                RowMinimum[i] = min(RowMinimum[i], matrix[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                colMaximum[i] = max(colMaximum[i], matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==RowMinimum[i] && matrix[i][j]==colMaximum[j]){
ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};