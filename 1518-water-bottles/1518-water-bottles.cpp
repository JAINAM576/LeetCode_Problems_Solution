class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while((numBottles/numExchange)!=0){
            int q=numBottles/numExchange;
            int rem=numBottles%numExchange;
            ans+=numBottles/numExchange;
            numBottles=rem+q;
        }
        return ans;
    }
};