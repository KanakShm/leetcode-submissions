class Solution {
public:
    bool matchingBrace(std::stack<char>& st, char c) {
        if (c == ')' && st.top() == '(') return true;
        if (c == '}' && st.top() == '{') return true;
        if (c == ']' && st.top() == '[') return true;
        return false;
    }

    bool isValid(string s) {
        /*
            ({)} x
            ([{}])
            [(])
            {(([]{}()))}
        */
        std::stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                // Check if the top element matches the closing brace
                if (st.empty() || !matchingBrace(st, s[i])) return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
