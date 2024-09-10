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
int gcd(int a,int b){
    if(a<=0)return b;
    return gcd(b%a,a);
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
       ListNode*temp=head;
       while(temp && temp->next!=NULL){
        int val=temp->val;
        int sval=temp->next->val;
        ListNode*temp1=temp->next;
        ListNode*temp2=new ListNode(gcd(val,sval));
        temp->next=temp2;
        temp2->next=temp1;
        temp=temp1;
     
       }
        return head;
    }
};