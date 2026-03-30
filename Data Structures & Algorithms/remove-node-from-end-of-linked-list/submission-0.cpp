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
        int len =0;
        ListNode* crawl=head;
        while(crawl)
        {
            len++;
            crawl=crawl->next;
        }    
        cout<<len;
        int target = len-n;
        if(target==0)
            return head->next;
        crawl=head;
        int count=0;
        while(crawl)
        {
            if(count==target-1)
                crawl->next=crawl->next->next;
            crawl=crawl->next;
            count++;
        }
        return head;
    }
};
