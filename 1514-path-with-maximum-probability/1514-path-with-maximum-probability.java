class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        double[] bellman = new double[n];
        bellman[start_node] = 1.0;
        
        for (int i = 0; i < n - 1; i++) {
            int j = 0;
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                double sp = succProb[j];
                
                if (bellman[u] * sp > bellman[v]) {
                    bellman[v] = bellman[u] * sp;
                }
                
                if (bellman[v] * sp > bellman[u]) {
                    bellman[u] = bellman[v] * sp;
                }
                j++;
            }
        }
        
        return bellman[end_node];
    }
}