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
            breadth first search approach
            append all the neighbours to a queue and iterate while queue is not empty
            need to check cycles so introduce a visited hashmap of pointers to nodes we have visted

            when we pop from the queue make a new node (if it doesnt exist), iterate through all the neighbours and create
            a new node if it doesnt already exist in the hashmap. create new vector of
            these neighbour nodes and append this vector to the curr node
        */

        if (!node) return nullptr;

        std::queue<Node*> q;
        std::unordered_map<int, Node*> umap;
        q.push(node);

        Node* first_copy = new Node(node->val);
        umap[first_copy->val] = first_copy;
        
        while (!q.empty()) {
            Node* n = q.front();

            // Create new node if it doesnt exist
            Node* node_copy;
            if (umap.find(n->val) == umap.end()) {
                node_copy = new Node(n->val);
                umap[node_copy->val] = node_copy;
            } else {
                node_copy = umap[n->val];
            }

            // Loop through the neighbours list and create new node (if it doesnt exist)
            std::vector<Node*> neighbors_copy;
            for (int i = 0; i < n->neighbors.size(); ++i) {
                if (!n->neighbors[i]) continue;

                Node* neighbor_copy;
                if (umap.find(n->neighbors[i]->val) == umap.end()) {
                    neighbor_copy = new Node(n->neighbors[i]->val);
                    umap[neighbor_copy->val] = neighbor_copy;
                    q.push(n->neighbors[i]);
                } else {
                    neighbor_copy = umap[n->neighbors[i]->val];
                }
                neighbors_copy.push_back(neighbor_copy);
            }

            node_copy->neighbors = neighbors_copy;
            q.pop();
        }

        return first_copy;
    }
};
