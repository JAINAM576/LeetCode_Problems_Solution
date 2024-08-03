class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp;
        int n =target.size();
        for(int i=0;i<n;i++){
            mp[target[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end()){
                return false;
            }
            mp[arr[i]]--;
        }
        for(auto it:mp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};