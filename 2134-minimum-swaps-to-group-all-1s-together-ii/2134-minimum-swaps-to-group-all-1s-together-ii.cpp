class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int numberOfOnes=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)numberOfOnes++;
        }
        int minZero=INT_MAX;
        int currZero=0;
        for(int i=0;i<numberOfOnes;i++){
            if(nums[i]==0)currZero++;
        }
        minZero=min(minZero,currZero);
        int s=0;
        int e=numberOfOnes;
        for(int i=numberOfOnes;i<(n+numberOfOnes-1);i++){
if(e>=n){
    e=e%n;
}
if(s>=n){
    s=s%n;
}
if(nums[s]==0){
    currZero=currZero-1;
}
if(nums[e]==0){
    currZero=currZero+1;

}
s++;
e++;

        minZero=min(minZero,currZero);

        }
        return minZero;
    }
};