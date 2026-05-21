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
    TreeNode* deleteNode(TreeNode* root, int key) {
        /*
            search through the tree for the value
            return left = deleteNode(root->left ...)
            when the value is found recurse to through the right side
            and attach the left to the end of the left of the right
            return treenode
        */

        if (!root) return nullptr;

        if (root->val == key) {
            return dfs(root->left, root->right);
        } else {
            root->left = deleteNode(root->left, key);
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    TreeNode* dfs(TreeNode* left, TreeNode* right) {
        if (!right) return left;
        if (!left) return right;

        right->left = dfs(left, right->left);
        return right;
    }
};