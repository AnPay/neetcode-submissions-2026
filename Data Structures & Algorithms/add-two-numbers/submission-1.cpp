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
        int carry =0;
        int sum=0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while(l1 && l2)
        {
            int v1 = l1->val;
            int v2=l2->val;
            int t = v1+v2+carry;
            sum = t%10;
            curr->next = new ListNode(sum);
            curr=curr->next;
            carry = t/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int v1 = l1->val;
            
            int t = v1+carry;
            sum = t%10;
            curr->next = new ListNode(sum);
            curr=curr->next;
            carry = t/10;
            l1=l1->next;    
        }
        while(l2)
        {
            int v2 = l2->val;
            
            int t = v2+carry;
            sum = t%10;
            curr->next = new ListNode(sum);
            curr=curr->next;
            carry = t/10;
            l2=l2->next;    
        }
        if(carry)
        {
            curr->next = new ListNode(carry);
            curr=curr->next;
        }
        return dummy->next;
    }
};
