/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* hc = head;
        unordered_map<Node*, Node*> HT;
        Node head_copy = Node(0);
        Node* dummy = &head_copy;
        while(hc)
        {
            dummy->next = new Node(hc->val);
            HT[hc]=dummy->next;
            dummy=dummy->next;
            hc=hc->next;
        }    
        hc=head;
        dummy = &head_copy;
        while(hc)
        {
            if (hc->random)
                dummy->next->random = HT[hc->random];
            else
                dummy->next->random = NULL;
            //dummy->next->random=HT[hc->random];
            hc=hc->next;
            dummy=dummy->next;
        }
        return head_copy.next;
    }
};
