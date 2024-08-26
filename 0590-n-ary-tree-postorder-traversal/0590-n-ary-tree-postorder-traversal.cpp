/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void PostTraverse(Node* root,vector<int>&post){
    if(root==NULL)return ;
    vector<Node*> vec=root->children;
    for(int i=0;i<vec.size();i++){
        PostTraverse(vec[i],post);
    }
    post.push_back(root->val);
    
}
    vector<int> postorder(Node* root) {
       vector<int> post;
       PostTraverse(root,post);
       return post;
    }
};