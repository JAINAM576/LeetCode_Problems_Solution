class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> vec(26,0);
        int ans=0;

        int n =allowed.size();
        for(int i=0;i<n;i++){
            vec[allowed[i]-'a']=1;
        }
        int word=words.size();
        for(int i=0;i<word;i++){
            int s=words[i].size();
            bool check=false;
                for(int j=0;j<s;j++){
                    if(vec[words[i][j]-'a']==0){
                        check=true;
                        break;
                    }
                }
                if(!check)ans++;
        }
        return ans;
        
    }
};