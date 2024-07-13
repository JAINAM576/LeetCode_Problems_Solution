class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            mp[positions[i]] = i;
        }
        sort(positions.begin(), positions.end());
        stack<int> Right;
        for (int i = 0; i < n; i++) {

            int idx = mp[positions[i]];

            if (directions[idx] == 'R') {
                Right.push(mp[positions[i]]);
            } else {
                if (Right.empty())
                    continue;
                while (!Right.empty()) {
                    if (healths[Right.top()] < healths[idx]) {
                        healths[mp[positions[i]]]--;
                        healths[Right.top()] = -1;
                        Right.pop();
                    } else if (healths[Right.top()] > healths[idx]) {
                        healths[Right.top()]--;
                        healths[idx] = -1;
                        break;

                    } else {
                        healths[Right.top()] = -1;
                        healths[idx] = -1;
                        Right.pop();
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (healths[i] != -1) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};


