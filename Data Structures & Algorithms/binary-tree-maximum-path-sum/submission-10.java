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
    int res = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        /*
            max path sum is sum of 
                curr + left + right
                curr + left
                curr + right
                curr
                no value should fall below 0
            
            traverse left and get the running sum
            traverse right and get running sum
            get the max path and return that

                        1
                    -2      -3
                  1    3  -2.  
                -1
        */

        dfs(root);
        return res;
    }

    int dfs(TreeNode root) {
        if (root == null) return 0;

        int left = Math.max(0, dfs(root.left));
        int right = Math.max(0, dfs(root.right));
        
        res = Math.max(root.val + left + right, res);
        return root.val + Math.max(left, right);

    }
}
