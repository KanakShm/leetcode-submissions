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
            dfs through the tree to get the smallest and recurse up k iterations (from nullptr)
            return that number
        */
        std::vector<int> output;
        TreeNode* smallest = dfs(root, output);
        return output[k - 1];
    }

    TreeNode* dfs(TreeNode* root, std::vector<int>& output) {
        if (!root) return nullptr;
        
        dfs(root->left, output);
        output.push_back(root->val);
        dfs(root->right, output);
        return root;
    }
};
