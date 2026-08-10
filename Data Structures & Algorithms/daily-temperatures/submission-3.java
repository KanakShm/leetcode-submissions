class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        /*
            initialise array of length of temperatures
            monotonic decreasing stack
                <temp, index>
            while current temp > top of stack
                pop
            
            38 40
            1. 5

            1 0 1 2 1 0 0
            res array -> index being considered - index of popped element
        */

        Deque<int[]> monoStack = new ArrayDeque<>();
        int[] res = new int[temperatures.length];
        for (int i = 0; i < temperatures.length; ++i) {
            int t = temperatures[i];
            while (!monoStack.isEmpty() && t > monoStack.peek()[0]) {
                int[] popped = monoStack.pop();
                res[popped[1]] = i - popped[1];
            }

            monoStack.push(new int[]{t, i});
        }

        return res;
    }
}
