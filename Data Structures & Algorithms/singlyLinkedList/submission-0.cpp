class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){}
        ListNode(int val,ListNode* next):val(val),next(next){}
};
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;
public:
    LinkedList() {
        head = new ListNode(-1);
        tail=head;
    }

    int get(int index) {
        int t=0;
        ListNode* temp=head->next;
        while(temp!=nullptr)
        {
            if( t == index)
                return temp->val;
        t++;
        temp=temp->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* nn = new ListNode(val);
        nn->next=head->next;
        head->next=nn;  
        if(nn->next == nullptr)
            tail=nn;  
    }
    
    void insertTail(int val) {
        ListNode* nn = new ListNode(val);
        tail->next = nn;
        tail=nn;    
    }

    bool remove(int index) {
        int t=0;
        ListNode* temp=head;
        while(temp!=nullptr && t<(index))
        {
            temp=temp->next;
            t++;
        }    
        if(temp!=nullptr && temp->next!=nullptr)
        {
            if(temp->next==tail)
                tail=temp;
            ListNode* todel = temp->next;
            temp->next = temp->next->next;
            delete todel;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int>res;
        ListNode* temp=head->next;
        while(temp!=nullptr)
        {
            res.push_back(temp->val);
            temp=temp->next;
        }    
        return res;  
    }
};
