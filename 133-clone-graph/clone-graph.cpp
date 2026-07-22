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
    void DFS(Node* node, Node* clone, unordered_set<Node*>& visited,
             unordered_map<Node*, Node*>& mpp) {
        if (!node)
            return;
        for (auto n : node->neighbors) {
            if (visited.count(n) == 0) {
                visited.insert(n);
                Node* newNode = new Node(n->val);
                clone->neighbors.push_back(newNode);
                mpp[n] = newNode;
                DFS(n, newNode, visited, mpp);
            } else {
                clone->neighbors.push_back(mpp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_set<Node*> visited;
        unordered_map<Node*, Node*> mpp;
        Node* cloneNode = new Node(node->val);
        visited.insert(node);
        mpp[node] = cloneNode;
        DFS(node, cloneNode, visited, mpp);
        return cloneNode;
    }
};