struct Node {
    Node* link[2];
    bool flag = false;
    Node() {
        for (int i = 0; i < 2; i++) {
            link[i] = NULL;
        }
    }
    bool containsKey(int bit) { return link[bit] != NULL; }
    void put(int bit, Node* node) { link[bit] = node; }
    Node* get(int bit) { return link[bit]; }
};
class Trie {
    Node* root;

   public:
    Trie() { root = new Node(); }

    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum |=(1<<i);
                node=node->get(1-bit);
            } else
            node=node->get(bit);
        }
        return maxNum;
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >=0; i--) {
            int bit=(num>>i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node);
            }
            node = node->get(bit);
        }
    }
};

class Solution {
	public:
		int findMaximumXOR(vector<int>& nums) {
		      Trie trie;
              for(int num : nums){
                trie.insert(num);
              }
              int maxi=0;
              for(int num :  nums){
                maxi=max(maxi,trie.getMax(num));
              }
              return maxi;
    	}
};
