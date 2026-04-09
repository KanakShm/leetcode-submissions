class Solution {
public:
    bool checkValidString(string s) {
        /*
            every time we see ( we append to a stack
            if we see ), we pop from the stack

            count the number of * we see and while we have ( on the stack we pop
                if the stack gets empty before we run out of * that is good
            
            if the stack is empty and we still have to go through the string
                if we see ), decrement a count from *
            ***)

            ***)))

            *(
        */

        std::stack<int> parenthesis;
        std::stack<int> stars;

        int star_count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                parenthesis.push(i);
            }

            if (s[i] == '*') {
                stars.push(i);
            }

            if (s[i] == ')') {
                if (parenthesis.empty()) {
                    if (stars.empty()) return false;
                    stars.pop();
                } else {
                    parenthesis.pop();
                }
            }
        }

        while (!parenthesis.empty() && !stars.empty() > 0) {
            if (stars.top() > parenthesis.top()) {
                parenthesis.pop();
                stars.pop();
            } else {
                break;
            }
        }

        return parenthesis.empty();
    }
};
