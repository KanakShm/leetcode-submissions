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
            queue -> add left and right 
            push back the whole queue
        */

        std::vector<std::vector<int>> level_order;
        std::queue<TreeNode*> q;

        if (root) q.push(root);
        while (!q.empty()) {
            std::vector<int> level;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* top = q.front();
                q.pop();
                level.push_back(top->val);

                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            level_order.push_back(level);
        }

        std::vector<int> res;
        for (int i = 0; i < level_order.size(); ++i) {
            res.push_back(level_order[i].back());
        }

        return res;
    }
};
