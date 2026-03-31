#include <array>

class MinStack {
    /*
        each value in the stack contains the previous min
        push -> we push value and also the current get min. update global min if necessary
        [3,8,6,9,pop,1, 2, pop]
        [4,3, 8,3 6,3  1,3  3,1]
    */
public:
    MinStack() : min(std::numeric_limits<int>::max()) {}
    
    void push(int val) {
        if (st.empty()) {
            std::array<int, 2> container = {val, val};
            st.push_back(container);
            min = val;
        } else {
            std::array<int, 2> container = {val, min};
            st.push_back(container);
            min = std::min(min, val);
        }
    }
    
    void pop() {
        std::array<int,2> top = st[st.size() - 1];
        min = top[1];
        st.pop_back();
    }
    
    int top() {
        return st[st.size() - 1][0];
    }
    
    int getMin() {
        return min;
    }

private:
    std::vector<std::array<int,2>> st;
    int min;
};
