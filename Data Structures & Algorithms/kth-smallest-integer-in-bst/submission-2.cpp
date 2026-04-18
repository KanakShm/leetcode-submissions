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
    int kthSmallest(TreeNode* root, int k) {
        /*
            dfs all the way down
            recurse back up k times
            return from left k--
            current node k--
            right node k--

            if (k == 0 return that value)
            dfs down
            after dfs k--;

                        4
                3               5
            2       
        */

        return dfs(root, k);
    }

    int dfs(TreeNode* root, int& k) {
        if (!root) return INT_MAX;

        int left = dfs(root->left, k);
        if (left != INT_MAX) return left;

        k--;

        if (k == 0) return root->val;
        int right = dfs(root->right, k);
        if (right != INT_MAX) return right;

        return INT_MAX;
    }
};
