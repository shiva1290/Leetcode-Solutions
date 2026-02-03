struct Node {
    Node* links[26];
    bool end=false;
    vector<string> suggestions;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node * get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    void setEnd(){
        end=true;
    }

    bool isEnd(){
        return end;
    }
    int suggSize(){
        return suggestions.size();
    }
    void pushSuggestion(string s){
        suggestions.push_back(s);
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
       Node * node=root;
       for(int i =0 ;i<word.size();i++){
        if(!node->containsKey(word[i])){
            node->put(word[i],new Node());
        }
        node=node->get(word[i]);
        if(node->suggSize()<3){
            node->pushSuggestion(word);
        }
       }
       node->setEnd();
    }

    vector<string> getSuggestions(string prefix) {
        Node * node=root;
        for(auto ch : prefix){
            if(!node->containsKey(ch)){
                return {};
            }
            node=node->get(ch);
        }
        return node->suggestions;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());

        Trie trie;

        for (string& product : products) {
            trie.insert(product);
        }

        vector<vector<string>> ans;
        string prefix = "";

        for (char ch : searchWord) {
            prefix += ch;
            ans.push_back(trie.getSuggestions(prefix));
        }

        return ans;
    }
};