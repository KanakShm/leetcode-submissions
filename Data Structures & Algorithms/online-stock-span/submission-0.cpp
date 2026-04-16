class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!stocks.empty() && stocks.top().first <= price) {
            res += stocks.top().second;
            stocks.pop();
        }

        stocks.push(std::make_pair(price, res));
        return res;
    }

    std::stack<std::pair<int, int>> stocks;
    /*
        each stock contains its own span
        stack contains price, span
        pop until the price is less than top of stack
        append price, span to stack
        return span
        span updates += top of stack's span every time we pop
    */
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */