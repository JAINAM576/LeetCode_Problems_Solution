class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

     int s=0;

     int e=0;
     int n=arr.size();
     if(n<=2)return false;
     while(e<n){
     
        while(e<n && arr[e]%2==0){
s=e+1;
e=s;
        }
        
        if(arr[e]%2==1){
               if ((e-s+1)==3)return true;
            e++;
        }
        
     }
     return false;   
    }
};