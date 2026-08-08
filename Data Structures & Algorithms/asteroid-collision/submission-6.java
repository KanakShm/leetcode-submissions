class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        /*
            stack
            positive elements on the stack
            while negative element > absolute of top of stack
                pop
            if the stack becomes empty then add the negative element
            always add positive element
        */

        Deque<Integer> space = new ArrayDeque<>();
        for (int i = 0; i < asteroids.length; ++i) {
            if (asteroids[i] > 0) {
                space.push(asteroids[i]);
            } else {
                while (!space.isEmpty() && space.peek() > 0 && 
                        Math.abs(space.peek()) < Math.abs(asteroids[i])) {
                    space.pop();
                }
                
                if (!space.isEmpty() && space.peek() > 0 && 
                    Math.abs(space.peek()) == Math.abs(asteroids[i])) {
                    space.pop();
                } else if (space.isEmpty() || space.peek() < 0) {
                    space.push(asteroids[i]);
                }
            }
        }

        int[] res = new int[space.size()];
        for (int i = 0; i < res.length; ++i) {
            res[i] = space.pollLast();
        }

        return res;
    }
}