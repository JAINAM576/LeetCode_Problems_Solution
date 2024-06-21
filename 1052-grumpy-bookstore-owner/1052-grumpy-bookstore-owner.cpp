class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int s=0;
        int e=0;
        int n= grumpy.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
        }
        while(e<n){
                //shrinking
                 int shrink_cond=e-s+1;
                 while(shrink_cond>minutes){
                    if(grumpy[s]==1){
                        sum-=customers[s];
                    }
                    s++;
                    shrink_cond=e-s+1;
                 }   
                //exapnding
                if(grumpy[e]==1){
                    sum+=customers[e];
                }
                ans=max(ans,sum);
                e++;
        }
        return ans;
    }
};