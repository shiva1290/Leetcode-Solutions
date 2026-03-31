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
        bool containsKey(char c) { return links[c - 'a'] != nullptr; }
        void putKey(char c, Node* node) { links[c - 'a'] = node; }
    };

    Node* root;
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->putKey(word[i], new Node());
            }
            node = node->links[word[i] - 'a'];
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->links[word[i] - 'a'];
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->links[prefix[i] - 'a'];
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