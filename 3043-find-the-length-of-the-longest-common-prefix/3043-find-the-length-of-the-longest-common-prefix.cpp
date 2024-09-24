class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string, int> mp;
        int ans=0;
        int n = arr1.size();
        for (int i = 0; i < n; i++) {
            string temp = "";
            stringstream obj;
            obj << arr1[i];
            obj >> temp;
            int len = temp.size();
            string temp1;
            for (int i = 0; i < len; i++) {
        
                temp1.push_back(temp[i]);
                mp[temp1] = 1;
            }
       
        }

      
         n=arr2.size();
           for (int i = 0; i < n; i++) {
            string temp = "";
            stringstream obj;
            obj << arr2[i];
            obj >> temp;
            int len = temp.size();
            string temp1;
            for (int i = 0; i < len; i++) {
              
                temp1.push_back(temp[i]);
                if(mp.find(temp1)!=mp.end()){
    
                   if((temp1.size())>ans)ans=temp1.size();
                }
            }
        }

        return ans;
    }
};