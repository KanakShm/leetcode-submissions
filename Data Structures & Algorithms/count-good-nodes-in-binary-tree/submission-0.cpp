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
    int goodNodes(TreeNode* root) {
        /*
            dfs through the tree
            as we dfs keep track of current max along that level
            if node is greater than current max then increment count

                    3
                3       null
            4       2
        */
        
        int max = root->val;
        int output = 0;
        dfs(root, max, output);
        return output;

    }

    void dfs(TreeNode* root, int max, int& output) {
        if (!root) return;

        if (root->val >= max) {
            max = root->val;
            output++;
        }

        dfs(root->right, max, output);
        dfs(root->left, max, output);
    }
};
