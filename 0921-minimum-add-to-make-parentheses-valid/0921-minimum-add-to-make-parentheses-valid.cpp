class Solution {
public:
    int minAddToMakeValid(string s) {
        int close=0,open=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open<=0){
                    close++;
                }
                else{
                    open--;
                }
            }
        }
        int ans=0;
        if(close==0 || open==0){
            ans=abs(close-open);
        }
        else {
            ans=close+open;
        }
        return ans;
    }
};