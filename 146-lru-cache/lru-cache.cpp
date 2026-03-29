class LRUCache {
public:
struct Node {
    int key;
    int val;
    Node* prev;
    Node * next;
    Node(int k,int v){
        key=k;
        val=v;
        prev=next=nullptr;
    }
};

int size;
unordered_map<int,Node*>mpp;
Node* head;
Node* tail;

void deleteNode(Node* node){
    Node* prevNode=node->prev;
    Node* nextNode=node->next;
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
}
void insertAfterHead(Node* node){
    Node* nextNode=head->next;
    head->next=node;
    node->prev=head;
    node->next=nextNode;
    nextNode->prev=node;
    
}
    LRUCache(int capacity) {
        size=capacity;
        mpp.clear();
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    int get(int _key) {
        if(mpp.find(_key)==mpp.end()) return -1;
        Node* node=mpp[_key];
        int val=node->val;
        deleteNode(node);
        insertAfterHead(node);
        return val;
    }
    
    void put(int _key, int value) {
        if(mpp.find(_key)!=mpp.end()){
            Node* node=mpp[_key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
            return;
        }
        if(mpp.size()>=size){
            Node* node=tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
            delete(node);
        }
        Node* node=new Node(_key,value);
        insertAfterHead(node);
        mpp[_key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */