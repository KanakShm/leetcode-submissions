/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}
*/

class Solution {
    public Node construct(int[][] grid) {
        /*
            scan through the array if we see that there are any values not 1
            then split recursively
                dfs function
            
            dfs: given coordinates of the search
            if not all 1s, split the coordinates into 4 equal sections
                is leaf to false
        
            each dfs should have 4 checks for 4 diff corners
            if a check passes then construct a node with is leaf true and isval true
            n^2logn

            recurse through to the bottom
            construct a leaf node
            if they are the same value merge together and return only one node
                leaf node or node that contains left right etc
            
            1 2 3 4 5
            1 2 3 4 5
            1 2 3 4 5
            1 2 3 4 5
        */

        return dfs(grid, 0, grid.length - 1, 0, grid[0].length - 1);
    }

    public Node dfs(int[][] grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        if (rowStart == rowEnd) {
            if (grid[rowStart][colStart] == 1) return new Node(true, true);
            return new Node(false, true);
        }

        Node newNode = new Node(true, false);
        int midRow = (rowStart + rowEnd) / 2;
        int midCol = (colStart + colEnd) / 2;

        newNode.topLeft = dfs(grid, rowStart, midRow, colStart, midCol);
        newNode.topRight = dfs(grid, rowStart, midRow, midCol + 1, colEnd);
        newNode.bottomLeft = dfs(grid, midRow + 1, rowEnd, colStart, midCol);
        newNode.bottomRight = dfs(grid, midRow + 1, rowEnd, midCol + 1, colEnd);

        if (newNode.topLeft.isLeaf && newNode.topRight.isLeaf && 
        newNode.bottomLeft.isLeaf && newNode.bottomRight.isLeaf &&
        newNode.topLeft.val == newNode.topRight.val && 
        newNode.topRight.val == newNode.bottomLeft.val && 
        newNode.bottomLeft.val == newNode.bottomRight.val) {
            return new Node(newNode.topLeft.val, true);
        }

        return newNode;
    }
}