class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int flips=0;
        int currentflipcounts=0;
        int n=nums.size();
        vector<int>fliped(n,false);
        for(int i=0;i<n;i++){
            if(i>=k && fliped[i-k]){
currentflipcounts--;
            }
            if(currentflipcounts%2==nums[i]){
                if((i+k)>n)return -1;
                currentflipcounts++;
                fliped[i]=true;
                flips++;
            }
        }
        return flips;
    }
};