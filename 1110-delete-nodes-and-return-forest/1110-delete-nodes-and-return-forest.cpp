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

void trav(TreeNode*root,int deleteVal,bool & check1, vector<TreeNode*>&ans,int idx,unordered_map<int,int> &mp){
    
    if(root==NULL )return ;
  if(root->val==deleteVal){
    if(root->left!=NULL){
        ans.push_back(root->left);
    }
     if(root->right!=NULL){
        ans.push_back(root->right);
    }
   
    mp[idx]=1;
    check1=true;
    return ;
  }

        // cout<<root->val<<endl;
    if(root->left !=NULL && root->left->val==deleteVal){
        //leaf node
        if(root->left->left==NULL && root->left->right==NULL){
            root->left=NULL;
        }
        //NODE WITH 2 CHILDERN
        else if(root->left->left!=NULL && root->left->right!=NULL){
                ans.push_back(root->left->left);
            
                    ans.push_back(root->left->right);
root->left=NULL;
        }
        // NODE WITH 1 CHILDREN LEFT SIDE
        else if(root->left->left!=NULL){
                ans.push_back(root->left->left);
root->left=NULL;
        }
        // NODE WITH 1 CHILDREN Right SIDE

        else if(root->left->right!=NULL){
                    ans.push_back(root->left->right);
root->left=NULL;
        }
        else{
root->left=NULL;
        }
        check1=true;
    }
   else  if(root->right !=NULL && root->right->val==deleteVal){
        //leaf node
        if(root->right->left==NULL && root->right->right==NULL){
            root->right=NULL;
        }
        //NODE WITH 2 CHILDERN
        else if( root->right->left!=NULL && root->right->right!=NULL){
                        ans.push_back(root->right->left);
                        ans.push_back(root->right->right);
root->right=NULL;
        }
        // NODE WITH 1 CHILDREN LEFT SIDE
        else if(root->right->left!=NULL){
                        ans.push_back(root->right->left);
root->right=NULL;
        }
        // NODE WITH 1 CHILDREN Right SIDE

        else if(root->right->right!=NULL){
                        ans.push_back(root->right->right);
root->right=NULL;
        }
        else{
root->right=NULL;
        }
        check1=true;
    }
    trav(root->left,deleteVal,check1,ans,idx,mp);
    trav(root->right,deleteVal,check1,ans,idx,mp);

}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
    
        ans.push_back(root);
        int n=to_delete.size();
     
       unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int m=ans.size();
            bool check1=false;
            for(int j=0;j<m;j++){
                if(mp[j])continue;
     trav(ans[j],to_delete[i],check1,ans,j,mp);

if(check1)break;
            }
        }
        vector<TreeNode*> ans1;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]->val;
            if(!mp[i]){
                ans1.push_back(ans[i]);
            }
        }
        return ans1;
    }
};