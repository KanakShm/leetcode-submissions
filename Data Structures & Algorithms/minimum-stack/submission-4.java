class MinStack {
    private Deque<Integer> stack;
    private Deque<Integer> monoStack;

    public MinStack() {
        stack = new ArrayDeque<>();
        monoStack = new ArrayDeque<>();
    }
    
    public void push(int val) {
        stack.push(val);
        if (monoStack.isEmpty() || monoStack.peek() >= val)
            monoStack.push(val);
    }
    
    public void pop() {
        if (!stack.isEmpty() && stack.peek().equals(monoStack.peek()))
            monoStack.pop();
        stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int getMin() {
        return monoStack.peek();
    }
}
