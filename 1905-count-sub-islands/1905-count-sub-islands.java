class Solution {
public int countSubIslands(int[][] grid1, int[][] grid2) {
int n = grid1.length, m = grid1[0].length;
int[] drow = {-1, 0, 1, 0}, dcol = {0, 1, 0, -1};
int[][] vis = new int[n][m];
int ans = 0;
for(int i=0;i<n;i++) {
for(int j=0;j<m;j++) {
if(vis[i][j] == 0 && grid2[i][j] == 1) {
if(helper(i, j, n, m, drow, dcol, vis, grid1, grid2)) ans++;
}
}
}
return ans;
}
static boolean helper(int row, int col, int n, int m, int[] drow, int[] dcol, int[][] vis, int[][] grid1, int[][] grid2) {
vis[row][col] = 1;
        boolean isIsland=true;

if(grid1[row][col] == 0) isIsland= false;
for(int i=0;i<4;i++) {
int nrow = row + drow[i];
int ncol = col + dcol[i];
if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid2[nrow][ncol] == 1) {
boolean isIsland1=helper(nrow, ncol, n, m, drow, dcol, vis, grid1, grid2);
    isIsland=isIsland&&isIsland1;
}
}
return isIsland;
}
}