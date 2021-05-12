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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret;
        
        if(l1==NULL && l2==NULL)
            return NULL;
        else if(l1==NULL)
        {
            ret=new ListNode(l2->val);
            l2=l2->next;
        }
        else if(l2==NULL)
        {
            ret=new ListNode(l1->val);
            l1=l1->next;
        }
        else if(l1->val>l2->val)
        {
            ret=new ListNode(l2->val);
            l2=l2->next;
        }
        else
        {
            ret=new ListNode(l1->val);
            l1=l1->next;
        }
        ListNode *tail=ret;
        while(l1!=NULL || l2!=NULL)
        {
            ListNode *tmp=NULL;
            if(l1==NULL)
            {
                tmp=new ListNode(l2->val);
                l2=l2->next;
            }
            else if(l2==NULL)
            {
                tmp=new ListNode(l1->val);
                l1=l1->next;
            }
            else if((l1->val)<(l2->val))
            {
                tmp=new ListNode(l1->val);
                l1=l1->next;
            }
            else
            {
                tmp=new ListNode(l2->val);
                l2=l2->next;
            }
            tail->next=tmp;
            tail=tail->next;
        }
        return ret;
    }
};