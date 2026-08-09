class StockSpanner {
    private Deque<int[]> stack;
    public StockSpanner() {
        /*
            monotonic decreasing stack
            add to stack <number, how many are less than that number>
            if greater than top
                pop until there is a number greater
                push the number and how many we popped + 1
            
            return the top + 1

            7 34 
            3 2
        */
        stack = new ArrayDeque<>();
    }
    
    public int next(int price) {
        int[] new_price = {price, 1};

        while (!stack.isEmpty() && price >= stack.peek()[0]) {
            new_price[1] += stack.peek()[1];
            stack.pop();
        }

        stack.push(new_price);
        return new_price[1];
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */