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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        /*
            dfs through bst and add at the end if root is null
            return the root

            if you need to add in the middle
                if val is less than root val but greater than the
                left side of the val. vice versa for right side
                construct a new node and have its right be equal to the current root's right
                return
            
                        5
                                7
                                    9
                            6    8
                                  
        */

        return dfs(root, val);
    }

    TreeNode* dfs(TreeNode* root, int val) {
        if (!root) {
            TreeNode* new_node = new TreeNode(val);
            return new_node;
        }

        if (val > root->val) {
           root->right = dfs(root->right, val);
        } else if (val < root->val) {
            root->left = dfs(root->left, val);
        }

        return root;
    }
};