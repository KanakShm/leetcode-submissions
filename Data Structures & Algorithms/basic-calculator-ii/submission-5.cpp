class Solution {
public:
    int calculate(string s) {
        /*
            set op as + and every time we see a new operator set that
            as op

            keep track of num
        */

        std::stack<int> numbers;
        char op = '+';
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num *= 10;
                num += (s[i] - '0');
            } 
            
            if (((s[i] < '0' || s[i] > '9') && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    numbers.push(num);
                } else if (op == '-') {
                    numbers.push(-num);
                } else if (op == '*') {
                    int prev = numbers.top();
                    numbers.pop();
                    numbers.push(prev * num);
                } else if (op == '/') {
                    int prev = numbers.top();
                    numbers.pop();
                    numbers.push(prev / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int res = 0;
        while (!numbers.empty()) {
            res += numbers.top();
            numbers.pop();
        }

        return res;
    }
};