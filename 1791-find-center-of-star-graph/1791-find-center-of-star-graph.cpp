class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
int v1=edges[0][0];
int v2=edges[0][1];
int v3=edges[1][0];
int v4=edges[1][1];
if(v1==v3 || v1==v4){
    return v1;
}
return v2;
    }
};