class Solution {
public:

int findHashCode(string s,int n,int low,unordered_map<char,int> &mp,bool first){

int val=0;



for(int i=n-1;i>=low;i--){
    val=val+(s[i]-'a');
    if(first)
      mp[s[i]]++;
}
return val;
}
    bool checkInclusion(string s1, string s2) {

unordered_map<char,int> mp;
    int n=s1.size();
    int n1=s2.size();

    int hash=findHashCode(s1,n,0,mp,true);
int initSize=mp.size();

    if(n1<n)return false;

    int hashS2=findHashCode(s2,n,0,mp,false);

        for(int i=0;i<n;i++){
            mp[s2[i]]++;
        }
        bool check=true;
        for(auto it:mp){
            if(it.second%2==1 || initSize!=mp.size()){check=false;break;}
        }
        if(check)return true;
    

    for(int i=n;i<n1;i++){
mp[s2[i-n]]--;
        hashS2=(hashS2-((s2[i-n]-'a')))+s2[i]-'a';
   mp[s2[i]]++;
        if(hash==hashS2){
             check=true;
        for(auto it:mp){
            if(it.second%2==1){check=false;break;}
        }
          if(check)return true;
        }
    }

    return false;
    }
};