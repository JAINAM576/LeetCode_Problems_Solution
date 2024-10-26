/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    unordered_map<int, vector<int>> same_level;

    int maxi = INT_MIN;

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        maxi = max(maxi, root->val);
        return mp[root->val] = max(left, right) + 1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        vector<int> level(maxi + 1, 0);
        queue<TreeNode*> q;
        int levelCurrent = 0;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {

            TreeNode* top = q.front();
            q.pop();

            level[top->val] = levelCurrent;
            if (top && top->left) {
                q.push(top->left);
            }
            if (top && top->right) {
                q.push(top->right);
            }
            if (q.front() == NULL) {
                levelCurrent++;
                q.pop();
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
        }
        for (int i = 1; i <= maxi; i++) {
            same_level[level[i]].push_back(i);
        }
        int n = queries.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> levelMaxi(same_level.size());
        for (auto it : same_level) {
            pair<int, int> maxiINlevel = {INT_MIN, INT_MIN};
            for (auto vec : it.second) {
                if (mp[vec] > maxiINlevel.first) {
                    maxiINlevel.second = maxiINlevel.first;
                    maxiINlevel.first = mp[vec];
                } else if (mp[vec] > maxiINlevel.second) {
                    maxiINlevel.second = mp[vec];
                }
            }
            if (it.second.size() == 1 &&
                maxiINlevel.first == maxiINlevel.second) {
                maxiINlevel.second = 0;
            }
            levelMaxi[it.first] = maxiINlevel;
        }
        for (int i = 0; i < n; i++) {
            int val = queries[i];
            int height = mp[val];
            int levelOfCuR = level[val];
            int maxiInLevel = 0;
            if (height == levelMaxi[levelOfCuR].first) {
                maxiInLevel = levelMaxi[levelOfCuR].second;
            } else {
                maxiInLevel = levelMaxi[levelOfCuR].first;
            }
            if(maxiInLevel==INT_MIN)maxiInLevel=0;
            ans[i] = levelOfCuR + maxiInLevel - 1;
        }

        return ans;
    }
};