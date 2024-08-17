class Solution {
        public long maxPoints(int[][] points) {
        int n = points.length;
        int m = points[0].length;

        long[] dp = new long[m];

        for (int j = 0; j < m; j++) {
            dp[j] = points[0][j];
        }

        for (int i = 1; i < n; i++) {
            long[] newDp = new long[m];

            long maxLeft = Long.MIN_VALUE;
            for (int j = 0; j < m; j++) {
                maxLeft = Math.max(maxLeft, dp[j] + j);
                newDp[j] = points[i][j] + maxLeft - j;
            }

            long maxRight = Long.MIN_VALUE;
            for (int j = m - 1; j >= 0; j--) {
                maxRight = Math.max(maxRight, dp[j] - j);
                newDp[j] = Math.max(newDp[j], points[i][j] + maxRight + j);
            }

            dp = newDp;
        }

        long result = Long.MIN_VALUE;
        for (int j = 0; j < m; j++) {
            result = Math.max(result, dp[j]);
        }

        return result;
    }
}