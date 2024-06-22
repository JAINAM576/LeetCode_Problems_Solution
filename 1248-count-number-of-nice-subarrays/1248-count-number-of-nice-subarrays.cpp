class Solution {
public:
    int countSubarrayAtmostK(vector<int>& nums, int k){
        int ans=0;

        int count=0;

        int s=0;

        

        int n =nums.size();
        for(int e=0;e<n;e++){
            
            if(nums[e]%2==1)count++;
            while(s<=e && count>k){
                if(nums[s]%2==1)count--;
                s++;
            }
            ans+=e-s+1;
            
        }
        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return (countSubarrayAtmostK(nums,k)-countSubarrayAtmostK(nums,k-1));

    }
};