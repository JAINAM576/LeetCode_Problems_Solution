class Solution {
public:
static bool onHighestDegree(const  pair<int,int> &a,const  pair<int,int> &b){
return a.second>b.second;
}
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj(n,{0,0});
        unordered_map<int,int> importance;
        int length=roads.size();
        for(int i=0;i<length;i++){
           adj[roads[i][0]]={roads[i][0], adj[roads[i][0]].second+1};
           adj[roads[i][1]]={roads[i][1], adj[roads[i][1]].second+1};


        }
        sort(adj.begin(),adj.end(),onHighestDegree);
        int highest=n;
        for(auto it:adj){
            if(importance[it.first]==0)
                importance[it.first]=highest;
            highest--;
        }
        long long sum=0;
        for(int i=0;i<length;i++){
            sum+=importance[roads[i][0]]+importance[roads[i][1]];
        }
        return sum;


    }
};