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
    int rob(TreeNode* root) {
        /*
            Dynamic programming via cache
            dfs all the way to the end
            each dfs we take the value 
                traverse two accross
            or leave the value
                traverse one accross
            cache the result that gives us the largest sum

                        1
                            2
                        3       5
                    4       2
        */
        std::unordered_map<TreeNode*, int> dp;
        return robHouse(root, dp);
    }

    int robHouse(TreeNode* root, std::unordered_map<TreeNode*, int>& dp) {
        if (!root) return 0;
        if (dp.find(root) != dp.end()) return dp[root];

        // Rob the house
        int rob = root->val;
        if (root->left) {
            rob += robHouse(root->left->left, dp);
            rob += robHouse(root->left->right, dp);
        }

        if (root->right) {
            rob += robHouse(root->right->right, dp);
            rob += robHouse(root->right->left, dp);
        }

        // Dont rob the house (skip)
        int leave = robHouse(root->left, dp) + 
                    robHouse(root->right, dp);
        
        dp[root] = std::max(rob, leave);
        return dp[root];
    }
};