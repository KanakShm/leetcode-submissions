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
    bool isBalanced(TreeNode* root) {
        /*
            traverse binary tree left and then right
            if height of left - right > 1 then return false
        */
        bool is_balanced = true;
        int val = dfs(root, is_balanced);
        return is_balanced;
    }

    int dfs(TreeNode *root, bool& is_balanced) {
        if (!root) return -1;

        int left_depth = dfs(root->left, is_balanced) + 1;
        int right_depth = dfs(root->right, is_balanced) + 1;

        if (std::abs(left_depth - right_depth) > 1) 
            is_balanced = false;
        
        return std::max(left_depth, right_depth);
    }
};
