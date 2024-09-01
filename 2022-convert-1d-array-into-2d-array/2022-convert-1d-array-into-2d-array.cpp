class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>vec(m);
        int row=0;
        int size=original.size();
        if((n*m)!=size)return {};


        for(int i=0;i<size;i++){
vec[row].push_back(original[i]);
if(vec[row].size()==n)row++;
        }
        return vec;
    }
};