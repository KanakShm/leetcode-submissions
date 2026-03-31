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
    std::unordered_map<int, int> umap;
    int idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
            Go through the inorder and preorder list
            the first element in the preorder list will be the root
            Everything to the left of that element in the inorder list will be the left
            Everything to the right of that element in the inorder list will be the right
            we need to access inorder in order 1 so build a hashmap
        */
        for (int i = 0; i < inorder.size(); ++i) {
            umap[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size() - 1);
    }

    TreeNode* dfs(std::vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr; // case where left side doesnt have any nodes left to add
        if (idx >= preorder.size()) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx]);
        int mid_idx = umap[preorder[idx++]];

        root->left = dfs(preorder, left, mid_idx - 1);
        root->right = dfs(preorder, mid_idx + 1, right);
        return root;
    }
};
