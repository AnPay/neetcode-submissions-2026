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
/*
Pattern: fast pointer/ slow pointer with dummy head
State:
Transition:
Invariant:

*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fptr=&dummy;
    ListNode* sptr = &dummy;
    int fast = n;
    while(fast--)
        fptr=fptr->next;
    while(fptr->next)
    {
        sptr=sptr->next;
        fptr=fptr->next;
    }    
    sptr->next=sptr->next->next;
    return dummy.next;
    }
};
