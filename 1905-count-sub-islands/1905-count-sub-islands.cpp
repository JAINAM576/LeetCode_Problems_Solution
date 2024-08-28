class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}} ;
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid2) {
        if (i >= n || i < 0 || j < 0 || j >= m)
            return;

        grid2[i][j] = 0;
        // if ((i - 1) >= 0 && grid2[i - 1][j] == 1) {
        //     dfs(i - 1, j, n, m, grid2);
        // }
        // if ((j - 1) >= 0 && grid2[i][j - 1] == 1) {
        //     dfs(i, j - 1, n, m, grid2);
        // }
        // if ((i + 1) < n && grid2[i + 1][j] == 1) {
        //     dfs(i + 1, j, n, m, grid2);
        // }
        // if ((j + 1) < m && grid2[i][j + 1] == 1) {
        //     dfs(i, j + 1, n, m, grid2);
        // }
        for (auto& direction : directions) {
            int nrow = i + direction[0];
            int ncol = j + direction[1];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid2[nrow][ncol] == 1)
                dfs(nrow, ncol, n, m, grid2);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid1.size();
        int m = grid1[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                    dfs(i, j, n, m, grid2);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    dfs(i, j, n, m, grid2);
                    count++;
                }
            }
        }
        return count;
    }
};