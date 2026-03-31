#include <string>

class Solution {
public:
    int operate(int a, int b, std::string character) {
        if (character == "+") return a + b;
        if (character == "-") return a - b;
        if (character == "*") return a * b;
        if (character == "/") return a / b;
        return -999999;
    }

    int evalRPN(vector<string>& tokens) {
        /*
            Go through the array and push numbers onto stack
            If we find an operator then pop the last two elements and operate
            push the result back onto the stack
        */

        std::stack<int> st;
        std::for_each(tokens.begin(), tokens.end(), [&](std::string character) {
            if (character == "+" || character == "-" || character == "*" || character == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(operate(a, b, character));
            } else {
                st.push(std::stoi(character));
            }
        });

        return st.top();
    }
};
