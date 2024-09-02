class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long  sum=0;
        int n=chalk.size();
        for(int i=0;i<n;i++){
            sum+=chalk[i];
        }
        while(k>=sum)k=k-sum;
        for(int i=0;i<n;i++){
            if(chalk[i]>k){
                return i;
            }
            k=k-chalk[i];
        }
        return 0;
    }
};