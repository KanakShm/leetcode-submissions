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
    int maxDepth(TreeNode* root) {
        /*
            traverse the tree left and then right
            call recursively the max integer and only update the integer if it is a max
        */

        if (!root) {
            return 0;
        }

        int max_depth_left = maxDepth(root->left) + 1;
        int max_depth_right = maxDepth(root->right) + 1;

        return std::max(max_depth_left, max_depth_right);
    }
};
