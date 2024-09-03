class Solution {
public:
int sumOfChar(string s){
    int sum=0;
    int n=s.size();
for(int i=0;i<n;i++){
    sum+=s[i]-'0';
}
return sum;
}
string stringToNumbers(string s){
int n=s.size();
string temp;
for(int i=0;i<n;i++){
    int val;
    if(s[i]>=97 && s[i]<=122){
         val=s[i]-'a'+1;
    }
    else{
        val=s[i]-'0';
    }
    string l;
    stringstream obj;
    obj<<val;
    obj>>l;
    temp+=l;
}
return temp;
}
    int getLucky(string s, int k) {
        int sum=0;
        int n=s.size();
        if(k==1){
          string s1=stringToNumbers(s);
          return sumOfChar(s1);
        }
        string temp;
       int val;
        while(k){
         s= stringToNumbers(s);
         cout<<s<<" "<<endl;
      val=   sumOfChar(s);
         stringstream obj;
         obj<<val;
         obj>>s;
k--;
        }

        
        return val;
    }
};