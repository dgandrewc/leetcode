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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode;
        ListNode *ret=ans;
        
        int ru=0;
        while(1)
        {
            if(l1==NULL)
            {
                (ans->val)=((l2->val)+ru)%10;
                ru=((l2->val)+ru)/10;
            }
            else if(l2==NULL)
            {
                (ans->val)=((l1->val)+ru)%10;
                ru=((l1->val)+ru)/10;
            }
            else
            {
                (ans->val)=((l1->val)+(l2->val)+ru)%10;
                ru=((l1->val)+(l2->val)+ru)/10; 
            }
            
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
            
            if(l1==NULL && l2==NULL)
            {
                ans->next=NULL;
                if(ru!=0)
                {
                    ListNode *t=new ListNode;
                    t->val=ru;
                    ans->next=t;
                    ans=ans->next;
                }
                break;
            }
            ListNode *t=new ListNode;
            ans->next=t;
            ans=ans->next;
        }
        return ret;
    }
};