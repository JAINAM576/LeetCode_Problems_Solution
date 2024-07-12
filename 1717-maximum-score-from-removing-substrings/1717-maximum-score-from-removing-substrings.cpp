class Solution {
public:
    int maximumGain(string s, int x, int y) {
    
       int n=s.size();
       int ans=0;
    stack<char> st;
    
       if(y>x){
       for(int i=0;i<n;i++){
if(s[i]=='a' && !st.empty() && st.top()=='b'){
    st.pop();
    ans+=y;
}
else{
    st.push(s[i]);
}
       }
       int size=st.size();
       int j=size;
       while(!st.empty()){
s[j-1]=st.top();
j--;
st.pop();
       }
       for(int i=0;i<size;i++){
        if(s[i]=='b' && !st.empty() && st.top()=='a'){
    st.pop();
    ans+=x;
}
else{
    st.push(s[i]);
}
       }
    
       }
       else{
            for(int i=0;i<n;i++){
if(s[i]=='b' && !st.empty() && st.top()=='a'){
    st.pop();
    ans+=x;
}
else{
    st.push(s[i]);
}
       }
       int size=st.size();
       int j=size;
       while(!st.empty()){
s[j-1]=st.top();
j--;
st.pop();
       }
       for(int i=0;i<size;i++){
        if(s[i]=='a' && !st.empty() && st.top()=='b'){
    st.pop();
    ans+=y;
}
else{
    st.push(s[i]);
}
       }
       }
       return ans;
    }
};