class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->next = NULL;
            this->next = NULL;
        }
    };
    
    Node * head = new Node(0,0);
    Node * tail = new Node(0,0);
    
    unordered_map<int, Node*> mp;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insertNode(Node* currNode){
        currNode->next = head->next;
        head->next->prev = currNode;
        head->next = currNode;
        currNode->prev = head;
        mp[currNode->key] = currNode;
    }
    
    void deleteNode(Node* currNode){
        mp.erase(currNode->key);
        currNode->next->prev = currNode->prev;
        currNode->prev->next = currNode->next;
    
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp = mp[key];
            deleteNode(temp);
            insertNode(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            deleteNode(mp[key]);
        if(mp.size()==cap)
            deleteNode(tail->prev);
        
        insertNode(new Node(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */