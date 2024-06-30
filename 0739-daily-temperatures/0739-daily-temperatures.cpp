class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> Indices;
        vector<int> ans(temp.size(), 0);
        Indices.push(0);
        for (int i = 1; i < temp.size(); i++) {
            int n = Indices.top();
            if (!Indices.empty()) {
                while (temp[n] < temp[i]) {
                    ans[n] = i - n;
                    Indices.pop();
                    
                    if(Indices.empty())break;
                    n = Indices.top();
                }
            }

            Indices.push(i);
        }

        return ans;
    }
};
