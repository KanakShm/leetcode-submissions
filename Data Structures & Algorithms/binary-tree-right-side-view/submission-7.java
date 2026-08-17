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
    public List<Integer> rightSideView(TreeNode root) {
        /*
            level order traversal and only add the last element to res
                bfs by popping whole queue each time
        */
        if (root == null) return new ArrayList<>();
        Deque<TreeNode> q = new ArrayDeque<>();
        List<Integer> res = new ArrayList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int n = q.size();
            while (n > 0) {
                TreeNode node = q.poll();
                n--;

                if (n == 0) res.add(node.val);
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
        }

        return res;
    }
}
