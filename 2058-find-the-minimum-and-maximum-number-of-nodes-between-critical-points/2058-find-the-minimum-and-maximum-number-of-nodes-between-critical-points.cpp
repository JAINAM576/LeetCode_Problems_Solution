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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> Distance(2,-1);
        int previous=-1;
        previous=head->val;
        pair<int,int> Maximums={INT_MIN,INT_MAX};
        int Minimum=INT_MAX;

        head=head->next;
        int pos=2;
        int currentPos=-1;
        while(head->next!=NULL){
            //For Maxima 
if(head->val>previous && head->next->val  < head->val){
    Minimum=min(Minimum,pos);
    Maximums.first=max(Maximums.first,pos);
    if(currentPos==-1)currentPos=pos;
    else{
        Maximums.second=min(pos-currentPos, Maximums.second);
        currentPos=pos;
    }

}
//FOR MINIMA
else if (head->val<previous && head->next->val  > head->val){
    Minimum=min(Minimum,pos);
    Maximums.first=max(Maximums.first,pos);
     if(currentPos==-1)currentPos=pos;
    else{
        Maximums.second=min(pos-currentPos, Maximums.second);
        currentPos=pos;
    }
}
previous=head->val;
head=head->next;


pos+=1;
        }
        if(Maximums.first==INT_MIN || Minimum==INT_MAX || Maximums.first==Minimum) return Distance;
         
         Distance[0]=Maximums.second;
         Distance[1]=Maximums.first-Minimum;

return Distance;       
    }
};