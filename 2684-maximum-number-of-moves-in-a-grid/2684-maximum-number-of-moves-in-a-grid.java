class Solution {
    public int trav(int i, int j, int n, int m, int cur, int[][] grid, int[][] dp) {
        if (i >= n || j >= m || i < 0) return 0;

        int moves = 0;
        int moves1 = 0;
        int moves2 = 0;
if(dp[i][j]!=-1)return dp[i][j];
        if ((j + 1) < m && cur < grid[i][j + 1]) {
            moves = 1 + trav(i, j + 1, n, m, grid[i][j + 1], grid, dp);
        }
        if ((i - 1) >= 0 && (j + 1) < m && cur < grid[i - 1][j + 1]) {
            moves1 = 1 + trav(i - 1, j + 1, n, m, grid[i - 1][j + 1], grid, dp);
        }
        if ((i + 1) < n && (j + 1) < m && cur < grid[i + 1][j + 1]) {
            moves2 = 1 + trav(i + 1, j + 1, n, m, grid[i + 1][j + 1], grid, dp);
        }

        return dp[i][j] = Math.max(moves, Math.max(moves1, moves2));
    }

    public int maxMoves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] dp = new int[n + 1][m + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, trav(i, 0, n, m, grid[i][0], grid, dp));
        }

        return ans;
    }
}
