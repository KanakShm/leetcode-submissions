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
            create a deepcopy do dfs through the neighbours
            for each node, we create a copy within hashmap
                hashmap<old, new>
            create res node a copy of node
            pass into dfs res and real
            update hashamp

            1  2 3 4
            2  1 3
            3  1 2
            4  1

            DFS:
                base case if either node is null
                for each of the real's neighbours we create a new node if
                we haven't already and link it to real via hashmap
                dfs all the way down
                we cant dfs into nodes we have already created
                if we have created the neighbour we append it to the 
                current node's neighbours
        */
        if (!node) return nullptr;
        std::unordered_map<Node*, Node*> copies;
        Node* new_node = new Node(node->val);
        copies[node] = new_node;
        dfs(new_node, node, copies);
        return new_node;
    }
    
    void dfs(Node* copy, Node* node, std::unordered_map<Node*, Node*>& copies) {
        /* go through all the neighbours, if the value exists in the hashmap
        we do not dfs into it but only append to the neighbours vector

        append to the vector as you iterate through it
        */

        if (!copy || !node) {
            return;
        }

        std::vector<Node*> real_neighbors = node->neighbors;
        std::vector<Node*> copy_neighbors;
        for (int i = 0; i < real_neighbors.size(); ++i) {
            if (copies.find(real_neighbors[i]) != copies.end()) {
                copy_neighbors.push_back(copies[real_neighbors[i]]);
            } else {
                Node* new_node = new Node(real_neighbors[i]->val);
                copies[real_neighbors[i]] = new_node;
                copy_neighbors.push_back(new_node);
                dfs(new_node, real_neighbors[i], copies);
            }
        }
        copy->neighbors = copy_neighbors;
    }
};
