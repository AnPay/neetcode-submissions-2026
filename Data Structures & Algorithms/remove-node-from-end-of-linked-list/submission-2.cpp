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
Pattern:LL
State: 
Transition: 
Invariant:
Complexity: O(n)
Edge case: empty, first node, last node,
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len =0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp = temp->next;
        }    
        cout<<"len:"<<len<<"\n";
        temp=head;
        n = len-n-1;
        if(n==-1)
            return head->next;
        while(n&&temp)
        {
            n--;
            temp=temp->next;
        }
        if(temp->next)
            temp->next=temp->next->next;
        return head;
    }
};
