/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int res = 0;
    int curr = 0;
    public int kthSmallest(TreeNode root, int k) {
        /*
            recurse left to the bottom
            then dfs back up k times
                first left, curr then right
            
            when we get to the end, increment a counter
            if the counter is = k, then return that number

            dfs left, k++, dfs right
        */
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode root, int k) {
        if (root == null) return;

        dfs(root.left, k);
        curr++;

        if (curr == k) {
            res = root.val;
            return;
        }
        
        dfs(root.right, k);
    }
}
