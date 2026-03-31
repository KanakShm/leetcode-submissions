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
    int diameterOfBinaryTree(TreeNode* root) {
        /*
            traverse the binary tree
            at each node compute the max height
            keep track of a global diameter integer
            at each iteration, mark the diameter as the max between the left + right and current
            max diameter
        */
        int diameter = INT_MIN;
        dfs(root, diameter);
        return diameter;
    }

    int dfs(TreeNode *root, int &diameter) {
        if (!root) return -1;

        int left_depth = dfs(root->left, diameter) + 1;
        int right_depth = dfs(root->right, diameter) + 1;
        diameter = std::max(diameter, left_depth + right_depth);
        return std::max(left_depth, right_depth);
    }
};
