/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        /*
            Give boundaries
            loop through the boundaries and check if any numbers mismatch
            If they do then recurse with new boundaries
            If they dont mismatch then we dont need to create new nodes
            return the current node
        */

        Node* root = new Node();
        return dfs(grid, root, 0, 0, grid.size());
    }

    Node* dfs(std::vector<std::vector<int>>& grid, Node* root, int row, int col, int n) {
        if (!root) return nullptr;
        if (n == 1) {
            root->val = grid[row][col];
            root->isLeaf = true;
            return root;
        }

        int curr_val = grid[row][col];
        for (int i = row; i < row + n; ++i) {
            for (int j = col; j < col + n; ++j) {
                if (grid[i][j] != curr_val) {
                    Node* upper_left = new Node();
                    root->topLeft = dfs(grid, upper_left, row, col, n / 2);

                    Node* upper_right = new Node();
                    root->topRight = dfs(grid, upper_right, row, col + n / 2, n / 2);

                    Node* bottom_left = new Node();
                    root->bottomLeft = dfs(grid, bottom_left, row + n / 2, col, n / 2);

                    Node* bottom_right = new Node();
                    root->bottomRight = dfs(grid, bottom_right, row + n / 2, col + n / 2, n / 2);

                    root->isLeaf = false;
                    return root;
                }
            }
        }

        root->val = grid[row][col];
        root->isLeaf = true;
        return root;
    }
};