/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]=1;
        }
        vector<int> ans;
        ListNode*temp=head;
        while(temp!=NULL){
        if(mp.find(temp->val )  ==mp.end()) ans.push_back(temp->val);
            temp=temp->next;
        }
        ListNode*modified;
        ListNode* temp1;
        int n=ans.size();
        for(int i=0;i<n;i++){
            if(modified==NULL){
                modified=new ListNode(ans[i]);
                temp1=modified;
            }
            else{
            temp1->next=new ListNode(ans[i]);
            temp1=temp1->next;
            }
        }
        return modified;
        
    }
};