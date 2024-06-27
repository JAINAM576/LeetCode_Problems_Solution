class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
int n=edges.size();
        vector<int> node_freq(n+2,0);
        for(int i=0;i<n;i++){
            node_freq[edges[i][0]]++;
            node_freq[edges[i][1]]++;

            if ( node_freq[edges[i][0]]==n)return  edges[i][0];
            if ( node_freq[edges[i][1]]==n)return  edges[i][1];


        }
        return 0;
    }
};