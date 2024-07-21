class Solution {
public:
vector<int> TopoLogicalSort(int k, vector<vector<int>>refAdj){
    vector<vector<int>> adj(k+1);
    vector<int> indegree(k+1,0);
    int n=refAdj.size();
    for(int i=0;i<n;i++){
        adj[refAdj[i][0]].push_back(refAdj[i][1]);
        indegree[refAdj[i][1]]++;
    }

    queue<int> q;
    vector<int> toposort;
    for(int i=1;i<=k;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top=q.front();
        q.pop();
        toposort.push_back(top);
        int adjSize=adj[top].size();
        for(int i=0;i<adjSize;i++){
indegree[adj[top][i]]--;
if(indegree[adj[top][i]]==0)q.push(adj[top][i]);
        }
    }

return toposort;
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<int> rowTopo=TopoLogicalSort(k,rowConditions);
        if(rowTopo.size()!=k)return {};
        vector<int> colTopo=TopoLogicalSort(k,colConditions);
        if(colTopo.size()!=k)return {};

        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                     if(rowTopo[i]==colTopo[j]){
                        ans[i][j]=rowTopo[i];
                        break;
                     }
                    }
        }

return ans;
       
    }
};