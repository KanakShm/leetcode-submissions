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
    bool isValidBST(TreeNode* root) {
        /*
            root->left < root && root->right > root && dfs(left) && dfs(right)
                return true
            
            dfs return is boolean, if false bubble it up and return false

                            5
                    4               6
                n       n       3       7
        */

        int max_left = INT_MIN;
        int max_right = INT_MAX;
        return dfs(root, max_left, max_right);
    }

    bool dfs(TreeNode* root, int max_left, int max_right) {
        if (!root) return true;

        if (root->left) {
            if (root->left->val >= root->val || root->left->val <= max_left) return false;
        }

        if (root->right) {
            if (root->right->val <= root->val || root->right->val >= max_right) return false;
        }

        if (!dfs(root->left, max_left, root->val) || !dfs(root->right, root->val, max_right)) return false;

        return true;
    }
};
