class Solution {
public:
  
    int nthUglyNumber(int n) {
     


      priority_queue<long long,vector<long long >,greater<long long >> pq;
      pq.push(1);
      n--;

      while(n--){
long long  top=pq.top();
while(!pq.empty() && pq.top()==top)
pq.pop();

pq.push(top*2);
pq.push(top*3);
pq.push(top*5);

      }

      return pq.top();
    }
};

