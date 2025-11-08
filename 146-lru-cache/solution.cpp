class LRUCache {
    struct Node {
        Node* prev;
        Node* next;
        int key, val;
        Node(int k = -1, int v = -1)
            : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

public:
    int size;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }
    LRUCache(int capacity) {
        size = capacity;
        mpp.clear();
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (mpp.find(key_) == mpp.end()) {
            return -1;
        }
        Node* node = mpp[key_];
        int val = node->val;
        deleteNode(node);
        insertAfterHead(node);
        return val;
    }

    void put(int key_, int value) {
        if (mpp.find(key_) != mpp.end()) {
            Node* node = mpp[key_];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
            return;
        }
        if (mpp.size() == size) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
            delete (node);
        }
        Node* node = new Node(key_, value);
        insertAfterHead(node);
        mpp[key_] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */