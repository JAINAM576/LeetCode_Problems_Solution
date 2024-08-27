class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
      vector<double> bellman(n,0);
      bellman[start_node]=1.0;
      for(int i=0;i<n-1;i++){
      bool ischange=false;
        int j=0;
        for(auto edge:edges){
            int u =edge[0];
            int v =edge[1];
            double sp=succProb[j];
            if(bellman[u]*sp>bellman[v]){
                bellman[v]=bellman[u]*sp;
                ischange=true;
            }
             if(bellman[v]*sp>bellman[u]){
                bellman[u]=bellman[v]*sp;
                ischange=true;
            }
j++;
        }
        if(!ischange)break;
      }
      return bellman[end_node];
    }
};