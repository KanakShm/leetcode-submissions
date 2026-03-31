/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
            breadth first search
            queue holds new nodes -> dont need to keep track of visited since all nodes are unique
            make a local queue and append that to the old queue once everything is popped
            need to keep a gloabal vector
            func returns a vector
        */

        std::vector<std::vector<int>> output;
        std::queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            std::vector<int> res;
            std::queue<TreeNode*> next_level;
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                res.push_back(curr->val);

                if (curr->left)
                    next_level.push(curr->left);
                
                if (curr->right)
                    next_level.push(curr->right);
            }
            output.push_back(res);
            q = next_level; 
        }
        return output;
    }
};
