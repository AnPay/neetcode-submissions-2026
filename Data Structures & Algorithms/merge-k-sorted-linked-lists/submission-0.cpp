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
    ListNode* dummyHead = new ListNode();
    
    
    ListNode* merge2List(ListNode* h1, ListNode* h2)
    {
        ListNode* node = dummyHead;
        while(h1 || h2)
        {
            int val1 = h1!=NULL?h1->val:INT_MAX;
            int val2 = h2!=NULL?h2->val:INT_MAX;
            if(val1<val2)
            {
                node->next = h1;
                h1= h1!=NULL?h1->next:NULL;
                cout<<"h1\n";
            }
            else
            {
                node->next = h2;
                h2= h2!=NULL?h2->next:NULL;
                cout<<"h2\n";
            }   
            node=node->next; 
            cout<<node->val<<"\n";
        }
        return dummyHead->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listCount = lists.size();
        if(listCount==0)
            return NULL;
        if(listCount==1)
            return lists[0];
        for(int i =1;i<listCount;i++)
        {
           ListNode* mergedHead =  merge2List(lists[i],lists[i-1]);
           cout<<mergedHead->val;
         
           lists[i]=mergedHead;
             //break;
        }
        return lists[listCount-1];

        
    }
};
