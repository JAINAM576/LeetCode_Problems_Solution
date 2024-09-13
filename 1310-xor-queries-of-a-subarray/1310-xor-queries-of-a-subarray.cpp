class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int queri=queries.size();
        for(int i=0;i<queri;i++){
            int ans1=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                ans1^=arr[j];
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};