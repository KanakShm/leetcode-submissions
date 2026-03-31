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
    int maxPathSum(TreeNode* root) {
        /*
            iterate dfs the tree
            if left or right is null return 0
            when we move back up, add either left and right or the max of left and right
            each iteration we keep track of a global maximum
                                    -15
                        10                      20
                    n       n               15      5
                                        -5      -6  n. n
        */
        int global_max = root->val;
        int res = dfs(root, global_max);
        return global_max;
    }

    int dfs(TreeNode* root, int& global_max) {
        if (!root) return 0;

        int left = dfs(root->left, global_max);
        int right = dfs(root->right, global_max);

        int total = left + right;
        int res = std::max(std::max(total, left), right);
        if (res < 0) {
            res = root->val;
        } else {
            res += root->val;
        }
        global_max = std::max(global_max, res);
        
        int result = std::max(std::max(left, right), 0);

        return result + root->val;
    }
};
