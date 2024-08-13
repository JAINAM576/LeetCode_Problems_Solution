class Solution {
    void trav(int ind,int target,vector<int>&nums,vector<vector<int>>&ans,vector<int>&current){
        if(target==0){
            ans.push_back(current);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            if(nums[i]>target)break;
            current.push_back(nums[i]);
            trav(i+1,target-nums[i],nums,ans,current);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>current;
        sort(candidates.begin(),candidates.end());
        trav(0,target,candidates,ans,current);
        return ans;
    }
};