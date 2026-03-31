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
    vector<int> rightSideView(TreeNode* root) {
        /*
            bfs the tree
            only add the final element from the queue to the return vector
        */

        std::queue<TreeNode*> q;
        if (root) 
            q.push(root);
        std::vector<int> output;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            std::queue<TreeNode*> q_next;
            std::vector<int> level; 
            while (!q.empty()) {
                level.push_back(q.front()->val);
                if (q.front()->left) {
                    q_next.push(q.front()->left);
                }

                if (q.front()->right) {
                    q_next.push(q.front()->right);
                }
                q.pop();
            }
            output.push_back(level[level.size() - 1]);
            q = q_next;
        }
        return output;
    }
};
