class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       vector<int> lower;
       vector<int> higher;
       int n=arrays.size();
       for(int i=0;i<n;i++){
        lower.push_back(arrays[i][0]);
        higher.push_back(arrays[i][arrays[i].size()-1]);
       }

int n1=lower.size();
int maxi=INT_MIN;
vector<int> prefixHigher(n1);
vector<int> postfixHigher(n1);
prefixHigher[0]=higher[0];
postfixHigher[n1-1]=higher[n1-1];

for(int i=1;i<n1;i++){
prefixHigher[i]=max(higher[i],prefixHigher[i-1]);
}

for(int i=n1-2;i>=0;i--){
postfixHigher[i]=max(higher[i],postfixHigher[i+1]);
}


for(int i=0;i<n1;i++){
    if(i==0){
        maxi=max(maxi,abs(lower[i]-postfixHigher[i+1]));
    }
    else if(i==n-1){
        maxi=max(maxi,abs(lower[i]-prefixHigher[i-1]));
    }
    else{
int max2=max(prefixHigher[i-1],postfixHigher[i+1]);
maxi=max(maxi,abs(lower[i]-max2));
    }
}
return maxi;
    
    }
};

// 1 4 1
// 3 5 3


// max(4)