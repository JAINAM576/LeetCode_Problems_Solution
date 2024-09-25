
class Node{
    public:
    unordered_map<char,Node*> mp;
    int count=0;
};

void fill(Node* root,string &s,int ind){
    if(ind==s.size())return;
    if(root->mp.find(s[ind])==root->mp.end()){
        Node* newnode=new Node();
        root->mp[s[ind]]=newnode;
        root=root->mp[s[ind]];
    }else root=root->mp[s[ind]];
    root->count++;
    fill(root,s,ind+1);
}

void get(Node* root,string &s,int ind,int &ans){
    ans+=root->count;
    if(ind==s.size())return;
    get(root->mp[s[ind]],s,ind+1,ans);
}

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root= new Node;
        for(int i=0;i<words.size();i++){
            fill(root,words[i],0);
        }
        vector<int> ans(words.size());
        for(int i=0;i<words.size();i++){
            get(root,words[i],0,ans[i]);
        }
        return ans;
    }
};