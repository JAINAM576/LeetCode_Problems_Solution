class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int > mp;
        
        
        for(char ch: word){
            mp[ch]++;
        }
        
        vector<int> vec;
        
        for(auto it:mp){
            vec.push_back(it.second);
        }
        
        
       
        sort(vec.begin(), vec.end(), greater<int>());
   
        
        int ans =0;
        int ct=1;
        for(int i: vec){
            
            if(ct<=8){
                ans += 1*i; 
            }
            else if(ct<=16){
                ans += 2*i;
            }
            else if(ct<=24){
                ans += 3*i;
            }
            else{
                ans += 4*i;
            }
            ct++;
        }
        return ans;
    }
};