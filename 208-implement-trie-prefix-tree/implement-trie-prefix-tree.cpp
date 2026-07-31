class Trie {
public:
    struct Node {
        Node* links[26];
        bool end = false;
        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }
        void setEnd() { end = true; }
        bool isEnd() { return end; }
        bool containsKey(char c){
            return links[c-'a']!=nullptr;
        }
        void setKey(char c,Node* node){
            links[c-'a']=node;
            return;
        }
    };
    Node* root;
    Trie() {
        root=new Node();
    }
    void insert(string word) { 
        Node* node=root;
        for(auto ch :  word){
            if(!node->containsKey(ch)){
                node->setKey(ch,new Node());
            }
            node=node->links[ch-'a'];
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node=root;
        for(auto ch: word){
            if(!node->containsKey(ch)){
                return false;
            }
               node=node->links[ch-'a'];
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
         Node* node=root;
        for(auto ch: prefix){
            if(!node->containsKey(ch)){
                return false;
            }
              node=node->links[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */