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
    public boolean isValidBST(TreeNode root) {
        /*
            Start at left and right boundaries as inf
            traverse left, update right boundary as current value
            traverse right, update left boundary as current value
        */

        return dfs(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    boolean dfs(TreeNode root, int left, int right) {
        if (root == null) return true;

        if (root.val <= left || root.val >= right ||
            !dfs(root.left, left, root.val) ||
            !dfs(root.right, root.val, right)) {
                return false;
            }
        
        return true;
    }
}
