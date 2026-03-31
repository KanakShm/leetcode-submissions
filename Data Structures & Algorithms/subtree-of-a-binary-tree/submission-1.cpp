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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /*
            iterate through the root tree
            is same tree <- pass in root->left and then root->right
            if any are true return true
        */
        if (!root) return false;

        if (isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) return true;
        if (!root && subRoot || root && !subRoot) return false;
        if (root->val != subRoot->val) return false;

        bool is_left_same = isSameTree(root->left, subRoot->left);
        bool is_right_same = isSameTree(root->right, subRoot->right);

        return is_left_same && is_right_same;
    }
};
