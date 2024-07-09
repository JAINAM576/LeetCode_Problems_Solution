class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans;
        int currCompletion=customers[0][0]+customers[0][1];
        ans=currCompletion-customers[0][0];
        int n=customers.size();
        for(
int i=1;
i<n;
i++
        ){
           currCompletion+= currCompletion<customers[i][0]?customers[i][0]-currCompletion:0;
            currCompletion=customers[i][1]+currCompletion;
             ans+=currCompletion-customers[i][0];

        }
        return ((double)ans/n);
    }
};