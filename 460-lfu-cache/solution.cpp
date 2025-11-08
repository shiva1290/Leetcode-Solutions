class LFUCache {
public:
    struct Node {
        int freq, key, value;
        Node* next;
        Node* prev;
        Node(int k, int v)
            : key(k), value(v), freq(1), next(nullptr), prev(nullptr) {} //
    };

    struct DLL {
        int size;
        Node* head;
        Node* tail;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size=0; //
        }

        void addFront(Node* node) {
            node->prev = head;
            node->next = head->next;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        void deleteNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
    };

    int capacity, currSize, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLL*> freqList;

    LFUCache(int c) {
        capacity = c;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqList[oldFreq]->deleteNode(node); //
        if (oldFreq == minFreq && freqList[oldFreq]->size == 0) {
            minFreq++;
        }
        node->freq++;
        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new DLL();
        }
        freqList[node->freq]->addFront(node);
    }

    int get(int key) {
        if (currSize == 0 || keyNode.find(key) == keyNode.end())
            return -1;
        else {
            Node* node = keyNode[key];
            updateFreq(node);
            return node->value;
        }
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreq(node);
        } else {
            if (capacity == currSize) { //
                DLL* list = freqList[minFreq];
                Node* remove = list->tail->prev;
                keyNode.erase(remove->key);
                list->deleteNode(remove);
                delete remove;
                currSize--;
            } //
            Node* node = new Node(key, value);
            if (freqList.find(1) == freqList.end()) {
                freqList[1] = new DLL();
            }
            freqList[1]->addFront(node);
            keyNode[key] = node;
            minFreq = 1;
            currSize++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */