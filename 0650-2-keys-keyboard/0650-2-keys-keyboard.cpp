class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
    int ans=0;
    int multi=1;
    int tempN=n;
    for(int i=2;i<((n/2)+1);i++){
while(tempN>0 && tempN%i==0 ){
    multi*=i;
    ans+=i;
    tempN/=i;
}
if(multi==n)break;
    }
    if(multi!=n){
        return n;
    }
    return ans;

    }
};

// A COPY=""  PASTE=""         N=1
// A COPY="A" PASTE=""         N=1
// AA COPY="A"  PASTE="A"      N=2