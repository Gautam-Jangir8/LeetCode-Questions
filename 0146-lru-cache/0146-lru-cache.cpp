class Node {
    public: 
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*>mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int size;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* p) {
        Node* pre = p->prev;
        Node* nex = p->next;
        pre->next = nex;
        nex->prev = pre;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    int get(int key) {
        // Means that the key value pair is not present in the map data structure
        if(mp.find(key)==mp.end()) {
            return -1;
        }
        // Means if the key value pair is present in the map data structure
        Node* p = mp[key];
        deleteNode(p);
        addNode(p);
        mp[key] = head->next;
        return head->next->val;
        
    }
    
    void put(int key, int value) {
        // If the key is already present in the map, so we have to just update the value
        if(mp.find(key)!=mp.end()) {
            Node* c = mp[key];
            deleteNode(c);
            c->val = value;
            addNode(c);
            mp[key] = head->next;
        } else {
            // If the map size if full i.e. equal to capacity, then we have to evict
            if(mp.size()==size) {
                Node* prev = tail->prev;
                deleteNode(prev);
                Node* l = new Node(key, value);
                addNode(l);
                mp.erase(prev->key);
                mp[key] = head->next;
            } else { // We do have space to insert the node
                Node* l = new Node(key, value);
                addNode(l);
                mp[key] = head->next;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */