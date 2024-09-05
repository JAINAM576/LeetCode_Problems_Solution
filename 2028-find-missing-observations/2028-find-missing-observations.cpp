class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long max_pos=6*n;
        vector<int> ans;
        int sum=0;
        for(int i=0;i<rolls.size();i++){
            sum+=rolls[i];
        }
      
        int total_size=rolls.size()+n;
      
        long long mean_find=(total_size*mean)-sum;
        long long  temp_mean_find=mean_find;
        cout<<mean_find<<endl;
        long long sum_after=0;
    if(mean_find>max_pos || mean_find<0)return {};
        for (long long  i = 1; i < n; ++i) {
        int partValue;
        if(mean_find/(n-i+1)>6){
            partValue=6;
        }
        else{
            partValue=mean_find / (n-i+1);
        }
        if(partValue<1){
            partValue=1;
        }
  
       sum_after+=partValue;
       ans.push_back(partValue);
        mean_find -= partValue;
    }

      if(mean_find>6){
            mean_find=6;
        }
   
   if(mean_find<1)
   {
       mean_find=1;
   }
   sum_after+=mean_find;
        ans.push_back(mean_find);

        if(sum_after!=temp_mean_find)return {};
   
return ans;
    }
};