/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

public:
        vector<int> vec;
   void inorder(TreeNode* root){
        if(root==NULL)return ;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);

    }
    void assignNewValues(TreeNode* &root,  vector<int> map){
if(root==NULL)return ;
assignNewValues(root->left,map);
       root->val=map[root->val];
        assignNewValues(root->right,map);

    }

    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        vector<int> node=vec;
        int n=node.size();
        vector<int> map(101,0);
        int sum=0;
        for(int i=n-1;i>=0;i--){
sum+=node[i];
map[node[i]]=sum;
        }
        assignNewValues(root,map);
        return root;
    }
};