class Solution {
    int[][] dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    public int orangesRotting(int[][] grid) {
        /*
            Put rotten fruit in queue
            bfs and increase minute after each queue dump
        */
        Deque<int[]> q = new ArrayDeque<>();
        int fresh_fruits = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 1) fresh_fruits++;
                if (grid[i][j] == 2) {
                    q.addLast(new int[] {i, j});
                }
            }
        }

        if (fresh_fruits == 0) return 0;

        int time = 0;
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int[] rotten_fruit = q.peekFirst();
                q.removeFirst();

                for (int j = 0; j < dir.length; ++j) {
                    int row = rotten_fruit[0] + dir[j][0];
                    int col = rotten_fruit[1] + dir[j][1];

                    if (row >= 0 && row < grid.length && 
                        col >= 0 && col < grid[0].length &&
                        grid[row][col] == 1) {
                            fresh_fruits--;
                            grid[row][col] = 2;
                            q.addLast(new int[] {row, col});
                    }
                }
            }

            if (!q.isEmpty()) time++;
        }

        return fresh_fruits == 0 ? time : -1;
    }
}
