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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /*
            dfs preorder until root and subroot match
            helper function to see if they are the same
        */

        return dfs(root, subRoot);
    }

    bool checkSubTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;

        if (root->val == subRoot->val) {
            if (checkSubTree(root->left, subRoot->left) &&
                checkSubTree(root->right, subRoot->right))
            return true;
        }

        return false;
    }

    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (root->val == subRoot->val && checkSubTree(root, subRoot))
            return true;
        
        return dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }
};
