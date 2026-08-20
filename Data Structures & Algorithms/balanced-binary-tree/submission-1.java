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
    public boolean isBalanced(TreeNode root) {
        /*
            dfs with int array as a return
            0 if not balanced and 1 if balanced
            the height of the tree (max of left and right)
        */

        return dfs(root)[0] == 1;
    }

    int[] dfs(TreeNode root) {
        if (root == null) return new int[] {1,0};

        int[] left = dfs(root.left);
        int[] right = dfs(root.right);

        if (left[0] != 1 || right[0] != 1 || Math.abs(right[1] - left[1]) > 1) {
            return new int[] {0, 0};
        }

        return new int[] {1, Math.max(left[1], right[1]) + 1};
    }
}
