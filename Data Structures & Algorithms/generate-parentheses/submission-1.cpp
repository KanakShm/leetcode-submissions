class Solution {
public: 
    std::vector<std::string> res;
    vector<string> generateParenthesis(int n) {
        /*
            ()
            n defines the number of ( and )
            ()()
            (())
            backtracking
            always choose ( until we run out, then choose )
            ((()))
            (()())
            (())()
            ()(())
            ()()()
        */

        int open = n;
        int close = n;
        std::string parentheses;
        dfs(parentheses, open, close, n);
        return res;
    }

    void dfs(std::string& parentheses, int open, int close, int n) {
        if (parentheses.size() == 2 * n) {
            res.push_back(parentheses);
            return;
        }

        if (open) {
            parentheses.push_back('(');
            dfs(parentheses, open - 1, close, n);
            parentheses.pop_back();
        }

        if (close && open < close) {
            parentheses.push_back(')');
            dfs(parentheses, open, close - 1, n);
            parentheses.pop_back();
        }
    }
};
