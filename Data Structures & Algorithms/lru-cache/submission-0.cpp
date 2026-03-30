class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
    Node(int k, int v) {
        this->key = k;
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> HT;
    int cap;
    int size;
    Node* head;
    Node* tail; 
    void remove(Node* node)
    {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next=nxt;
        nxt->prev = prev;
    }

    void insert(Node* node)
    {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev=prev;
        node->next=tail;
        tail->prev=node;
    }
public:
    LRUCache(int capacity) {
        cap=capacity;
        //size=0;
        HT.clear();
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next=tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(HT.find(key)!=HT.end())
        {
            Node* node = HT[key];
            remove(node);
            insert(node);
            return node->val;        
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if(HT.find(key)!=HT.end())
        {
            remove(HT[key]);
        }
        Node* newNode = new Node(key,value);
        HT[key]=newNode;
        insert(newNode);
        if(HT.size()>cap)
        {
            Node* lru = head->next;
            remove(lru);
            HT.erase(lru->key);
            delete lru;
        }

        
    }
};
