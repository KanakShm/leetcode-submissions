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
            level order traversal
            at each level pick the right most node
            put all nodes in a queue right to left
            pop all nodes in the queue at once and only append the node that is rightmost
                to res vector
            append all nodes left and right
        */
        if (!root) return {};

        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<int> res = {root->val};
        while (!q.empty()) {
            int n = q.size();
            int right_most = -1;
            for (int i = 0; i < n; ++i) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left) {
                    right_most = front->left->val;
                    q.push(front->left);
                }

                if (front->right) {
                    right_most = front->right->val;
                    q.push(front->right);
                }
            }

            if (right_most != -1) res.push_back(right_most);
        }

        return res;
    }
};
