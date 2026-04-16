class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        std::stack<int> stocks_cpy = stocks;
        int res = 0;
        while (!stocks_cpy.empty() && price >= stocks_cpy.top()) {
            res++;
            stocks_cpy.pop();
        }
        
        stocks.push(price);
        return res + 1;
    }

    std::stack<int> stocks;
    /*
        only need the last 4 days of stocks
        consecutive days
        stack
        push to stack, make a copy, pop from the stack until we find a number greater
        return the amount of numbers less than + 1
    */
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */