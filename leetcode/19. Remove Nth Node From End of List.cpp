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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nth=head;
        ListNode* tmp=head;
        int cnt=0;
        
        while(tmp!=NULL)
        {
            cnt++;
            tmp=tmp->next;
        }
        
        n=cnt-n-1;
        if(n==-1)
            return head->next;
        
        while(n)
        {
            n--;
            nth=nth->next;
        }

        if(nth->next!=NULL && (nth->next)->next!=NULL)
            nth->next=(nth->next)->next;
        else if(nth->next!=NULL && (nth->next)->next==NULL)
            nth->next=NULL;
        
        return head;
    }
};