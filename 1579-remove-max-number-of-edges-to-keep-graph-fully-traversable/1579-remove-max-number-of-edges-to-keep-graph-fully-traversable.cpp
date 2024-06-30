class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        int components;
        DSU(int n){
    parent.resize(n+1);
    for(int i=1;i<n+1;i++){
        parent[i]=i;
    }
    rank.resize(n+1);
    components=n;
        }
        int find(int x){
            if(x==parent[x]){
                return x;
            }
            return parent[x]=find(parent[x]);
        }
        void Union(int x,int y){
            int x_parent=find(x);
            int y_parent=find(y);
            if(x_parent==y_parent)return ;
            if(rank[x_parent]>rank[y_parent]){
                parent[y_parent]=x_parent;
            }
            else    if(rank[x_parent]<rank[y_parent]){
                parent[x_parent]=y_parent;
            }
            else{
                parent[x_parent]=y_parent;
    rank[y_parent]++;

            }
            components--;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);
        int length=edges.size();
        int edges_count=0;
for(int i=0;i<length;i++){

    int type=edges[i][0];
    int u=edges[i][1];
    int v=edges[i][2];
    if(type==3){
        bool  added=false;
        if(Alice.find(u)!=Alice.find(v)){
Alice.Union(u,v);
added=true;
        }
        if(Bob.find(u)!=Bob.find(v)){
Bob.Union(u,v);
added=true;
        }
        if(added){
            edges_count++;
        }
    }
}
for(int i=0;i<length;i++){

    int type=edges[i][0];
    int u=edges[i][1];
    int v=edges[i][2];
    if(type==1){
        
        if(Alice.find(u)!=Alice.find(v)){
Alice.Union(u,v);
 edges_count++;
        }

    }
        else if(type==2){

        if(Bob.find(u)!=Bob.find(v)){
Bob.Union(u,v);
 edges_count++;

        }
        }
       
    
}
if(Alice.components==1 && Bob.components==1){
    return length-edges_count;
}
return -1;

    }
};