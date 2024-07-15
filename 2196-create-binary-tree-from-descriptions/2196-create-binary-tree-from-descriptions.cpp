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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        int rootVal = 0;
       set<int>s;
        unordered_map<int, TreeNode*> nodes;

       for(int i=0;i<n;i++){
        if(nodes.find(descriptions[i][0])==nodes.end()){
            nodes[descriptions[i][0]]=new TreeNode(descriptions[i][0]);
        }
           if(nodes.find(descriptions[i][1])==nodes.end()){
            nodes[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
        }
        if(descriptions[i][2]==1){
        nodes[descriptions[i][0]]->left=nodes[descriptions[i][1]];
        }
        else{
        nodes[descriptions[i][0]]->right=nodes[descriptions[i][1]];

        }
        s.insert(descriptions[i][1]);
        
       }
       for(int i=0;i<n;i++){
        if(s.find(descriptions[i][0])==s.end())return nodes[descriptions[i][0]];
       }
       return nodes[50];
    }
};