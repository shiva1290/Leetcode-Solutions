class LRUCache {
public:
    struct Node {
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    int size;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mpp.clear();
    }

    void insertAfterHead(Node* node) {
        Node* nextnode = head->next;
        head->next = node;
        node->prev = head;
        nextnode->prev = node;
        node->next = nextnode;
    }
    void deleteNode(Node* node) {
        Node* nextnode = node->next;
        node->prev->next = nextnode;
        nextnode->prev = node->prev;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;
        else {
            int val = mpp[key]->val;
            deleteNode(mpp[key]);
            insertAfterHead(mpp[key]);
            return val;
        }
    }

    void put(int key, int value) {
        if (mpp.find(key) == mpp.end()) {
            Node* node = new Node(key, value);
            insertAfterHead(node);
            mpp[key] = node;
        } else {
            mpp[key]->val = value;
            deleteNode(mpp[key]);
            insertAfterHead(mpp[key]);
        }
        if (mpp.size() > size) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
            delete(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */