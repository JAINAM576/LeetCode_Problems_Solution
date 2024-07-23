class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        vector<int> counting(201,0);
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            counting[nums[i]+100]++;
            
        }
        for(int i=0;i<201;i++){
            if(counting[i]==0)continue;
            mp[counting[i]]++;
        }
        for(auto it:mp){
        
for(int i=200;i>=0;i--){
    if(counting[i]==it.first){
    int val=it.first;
        while(val--){
        ans.push_back(i-100);
        }
    }
}
            
          

        }
        return ans;


    }
};