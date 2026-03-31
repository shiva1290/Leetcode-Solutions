/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* DFS(Node* node,unordered_map<Node*,Node*>&mpp){
        if(node==NULL) return nullptr;
        if(mpp.find(node)!=mpp.end()) return mpp[node];
        Node* clone=new Node(node->val);
        mpp[node]=clone;
        for(auto it : node->neighbors){
            clone->neighbors.push_back(DFS(it,mpp));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mpp;
        return DFS(node,mpp);
    }
};