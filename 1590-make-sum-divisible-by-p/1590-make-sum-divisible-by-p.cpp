class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
   int sum=0;
for(int i=0;i<n;i++){
sum=(sum+nums[i])%p;
}
int rem=sum%p;

if(rem==0)return 0;

unordered_map<int,int>mp;
mp[0]=-1;
int ans=n;
int current=0;
for(int i=0;i<n;i++){
 current=(current+nums[i])%p;
 int prev=(current-rem+p)%p;
 if(mp.find(prev)!=mp.end()){
    ans=min(ans,i-mp[prev]);
 }
 mp[current]=i;
}
return ans==n?-1:ans;
    }
};

