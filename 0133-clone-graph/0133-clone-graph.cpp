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
  map<Node*, Node*> mp;
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    if (mp.find(node) != mp.end()) return mp[node];

    Node* newPar = new Node(node->val);
    mp[node] = newPar;

    for (auto x : node->neighbors) {
      newPar->neighbors.emplace_back(cloneGraph(x));
    }
    return newPar;
  }
};