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
    bool hasCycle(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return false;

        ListNode *sptr, *fptr;
        sptr=fptr=head;
        while(fptr->next!=NULL && fptr->next->next!=NULL)
        {
            sptr=sptr->next;
            fptr=fptr->next->next;
            if(sptr==fptr)
                return true;
        }    
        return false;
    }
};
