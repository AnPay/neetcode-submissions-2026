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
    void reorderList(ListNode* head) {
        //find tail
        //if we get DLL,
        // next=head->next
        // head->next=tail
        // tail=tail->prev
        // tail->next=next;

        //store nums in a vector and recreate LL

        //split from mid point
        //reverse 2nd list
        //adjust pointers
        if(head==NULL || head->next==NULL)
            return ;
        ListNode* mid;
        ListNode *sptr,*fptr;
        sptr=fptr=head;
        while(fptr!=NULL && fptr->next!=NULL)
        {
            sptr=sptr->next;
            fptr=fptr->next->next;
        }
        mid=sptr;
        cout<<sptr->val;
        //reverselist
        ListNode *curr,*prev,*next;
        prev=NULL;
        curr=mid->next;
        mid->next=NULL;
        while(curr->next){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        curr->next=prev;
        ListNode* t=curr;
        while(t)
            {cout<<t->val;t=t->next;}
        cout<<"\n";
        t=head;
        while(t)
            {cout<<t->val;t=t->next;}
        //now we have 2 lists
        ListNode* ptr=head;
        ListNode *ptr1, *ptr2;
        /*
        2,4,6
        10,8,

        2->10->4->8->6
        */
        next=NULL;
        while(ptr&& curr)
        {
            ptr1=ptr->next;
            next=curr->next;
            ptr->next=curr;
            curr->next=ptr1;
            curr=next;
            ptr=ptr1;
        }
       
        
        return ;
    }
};
