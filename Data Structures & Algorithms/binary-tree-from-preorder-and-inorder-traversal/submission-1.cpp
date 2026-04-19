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
    std::unordered_map<int, int> inorder_map;
    int preorder_idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
            each iteration of preorder gives us the root node of a subtree
            create hashmap of the indices of inorder
            iterate through preorder and get the l and r of a specific subarray
            build subarray recursively

            dfs base case if l - r + 1 == 0 return nullptr
            at the end return root

                        1
                    2
        */
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        return dfs(0, preorder.size() - 1, preorder, inorder);
    }

    TreeNode* dfs(int l, int r, std::vector<int>& preorder, std::vector<int>& inorder) {
        if (r - l + 1 <= 0) return nullptr;
        int mid = preorder[preorder_idx];
        preorder_idx++;
        TreeNode* new_node = new TreeNode(mid);
        new_node->left = dfs(l, inorder_map[mid] - 1, preorder, inorder);
        new_node->right = dfs(inorder_map[mid] + 1, r, preorder, inorder);
        return new_node;
    }
};
