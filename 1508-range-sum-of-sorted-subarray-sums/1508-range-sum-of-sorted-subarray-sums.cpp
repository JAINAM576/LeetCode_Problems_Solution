class Solution {
public:
long long mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum_arr;
        for(int i=0;i<n;i++){
            int sum=nums[i];
            sum_arr.push_back(sum);
            for(int j=i+1;j<n;j++){
sum=sum+nums[j];
            sum_arr.push_back(sum);

            }
        }
        sort(sum_arr.begin(),sum_arr.end());
        long long ans=0;
        for(int i=left-1;i<right;i++){
 ans=ans+(sum_arr[i]);
        }
        return ans%mod;
    }
};