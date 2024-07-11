class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string s2="";
        int noOfOpening=0;
        for(char c:s){
            if(c==')'){
                string temp;
                while(st.top()!="("){
                    string s1=st.top();
                    reverse(s1.begin(),s1.end());
temp+=s1;
st.pop();
                }

                st.pop();
                noOfOpening--;
                st.push(temp);
                if(noOfOpening==0){
                    s2+=temp;
                }
            }
            else{
                string s1;
        if(noOfOpening==0 && c!='('){
            s2+=c;
        }
        else if(c=='('){
                s1.push_back(c);
                st.push(s1);
                noOfOpening++;

        }
        else{
              s1.push_back(c);
                st.push(s1);
        }
            }
        }
      
        
        return s2;
    }
};

