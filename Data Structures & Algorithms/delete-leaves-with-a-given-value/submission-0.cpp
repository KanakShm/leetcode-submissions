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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        /*
            dfs to leaf then return nullptr if it is the target)
            root->left = dfs(root->left)
            need to check again if the current root is a leaf node
        */

        return dfs(root, target);
    }

    TreeNode* dfs(TreeNode* root, int target) {
        if (!root) return nullptr;

        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);

        if (!root->left && !root->right && root->val == target)
            return nullptr;

        return root;
    }
};