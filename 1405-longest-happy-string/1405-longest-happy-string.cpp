class Solution {
public:
int findMaxiIndex(vector<int>vec){
  int maxi=0;
      for(int i=0;i<3;i++){
if(vec[i]>vec[maxi]){
    maxi=i;
}
      }
return maxi;
}
    string longestDiverseString(int a, int b, int c) {
  vector<int> vec(3,0);
  vec[0]=a;
  vec[1]=b;
  vec[2]=c;

      
        string ans="";
vector<int>track(3,0);
        while(true){
      int maxi=findMaxiIndex(vec);
      cout<<maxi<<endl;
      for(int i=0;i<3;i++){
        cout<<"TRACK:"<<i<<" "<<track[i]<<endl;
      }
      for(int i=0;i<3;i++){
          cout<<"VEC:"<<i<<" "<<vec[i]<<endl;
      }
if(track[maxi]>=2){
    int temp=maxi;
    maxi=maxi==0?maxi=1:maxi==1?maxi=0:maxi==2?maxi=0:1;
    for(int i=0;i<3;i++){
        if(i==temp)continue;
if(vec[i]>vec[maxi]){
    maxi=i;
}
    }
    for(int i=0;i<3;i++){
        if(i==maxi)continue;
        track[i]=0;
    }
    if(vec[maxi]==0)break;
    vec[maxi]--;
    track[maxi]++;
    ans+=maxi+'a';
}else{
    for(int i=0;i<3;i++){
        if(i==maxi)continue;
        track[i]=0;
    }
    if(vec[maxi]==0)break;
    vec[maxi]--;
    track[maxi]++;
    ans+=maxi+'a';
}
        }
      return ans;
    }
};
