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
    	vector<int> maximizeXor(vector<int>& nums, vector<vector<int> >& queries) {
    		vector<vector<int>>offlineQueries(queries.size(),vector<int>(3,0));
            for(int i=0;i<queries.size();i++){
                offlineQueries[i][0]=queries[i][0];
                offlineQueries[i][1]=queries[i][1];
                offlineQueries[i][2]=i;
            }
            sort(offlineQueries.begin(),offlineQueries.end(),[](auto& a,auto &b){
                return a[1]<b[1];
            });
            sort(nums.begin(),nums.end());
            vector<int>ans(queries.size(),0);
            Trie trie;
            int i=0;
            for(auto& a : offlineQueries){
                while(i<nums.size() && nums[i]<=a[1]){
                trie.insert(nums[i]);
                i++;
                }
                if(i!=0) ans[a[2]]=trie.getMax(a[0]);
                else ans[a[2]]=-1;
            }
            return ans;
    	}
};
