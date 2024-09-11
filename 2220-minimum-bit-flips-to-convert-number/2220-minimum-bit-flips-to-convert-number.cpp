class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count =0;
       while(((int)max(start,goal))>0){
   
        int srem=start%2;
        int grem=goal%2;
      
        if(srem!=grem)count++;
        start/=2;
        goal/=2;
       }
       return count;
    }
};
// 8 4 2 1
// --------
// 1 0 1 0 
// 0 1 1 1


// 0 0 1 1
// 0 1 0 0 
