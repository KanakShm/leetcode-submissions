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
    Node* cloneGraph(Node* node) {
        /*
           Create old to new hashmap
           dfs through first node and create a new node if it doesnt exists already
           for the vector of nodes dfs through and create recursively
        */

        std::unordered_map<Node*, Node*> old_to_new;
        return dfs(old_to_new, node);
    }

    Node* dfs(std::unordered_map<Node*, Node*>& old_to_new, Node* node) {
        if (!node) return nullptr;

        if (old_to_new.find(node) == old_to_new.end()) {
            old_to_new[node] = new Node(node->val);
        }

        std::vector<Node*> neighbors = node->neighbors;
        for (int i = 0; i < neighbors.size(); ++i) {
            if (old_to_new.find(neighbors[i]) != old_to_new.end()) {
                old_to_new[node]->neighbors.push_back(old_to_new[neighbors[i]]);
            } else {
                old_to_new[node]->neighbors.push_back(dfs(old_to_new, neighbors[i]));
            }
        }

        return old_to_new[node];
    }
};
