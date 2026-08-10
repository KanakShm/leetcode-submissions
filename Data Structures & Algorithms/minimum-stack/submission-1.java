class MinStack {
    private List<Integer> stack;
    private List<Integer> monoStack;

    public MinStack() {
        /*
            arraylist that fills up
            10 50

            10
            monotonic decreasing stack
            if the pop is the same as whats on monotonic stack then pop
            that as well
        */
        stack = new ArrayList<>();
        monoStack = new ArrayList<>();
    }
    
    public void push(int val) {
        stack.add(val);
        if (monoStack.isEmpty() || val <= monoStack.get(monoStack.size() - 1))
            monoStack.add(val);
    }
    
    public void pop() {
        if (stack.isEmpty()) return;
        if (!monoStack.isEmpty() && stack.getLast().equals(monoStack.getLast())) {
            monoStack.remove(monoStack.size() - 1);
        }
        stack.remove(stack.size() - 1);
    }
    
    public int top() {
        return stack.getLast();
    }
    
    public int getMin() {
        return monoStack.getLast();
    }
}
