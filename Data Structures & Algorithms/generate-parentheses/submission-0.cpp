class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /*
            maintain open and close parenthesis count
            only add a parenthesis to the group if open count is <= n
            only add ) if close count is <= open count
            
            base case if the group length is equal to 2n

            (()())
        */
        int open_count = 0;
        int closed_count = 0;
        std::vector<std::string> result;
        std::string group;
        backtrack(n, open_count, closed_count, result, group);
        return result;
    }

    void backtrack(const int n, int open_count, int closed_count, 
                   std::vector<std::string>& result, std::string group)
    {
        if (group.size() == 2 * n) {
            result.push_back(group);
            return;
        }

        if (open_count < n) {
            group += '(';
            backtrack(n, open_count + 1, closed_count, result, group);
            group.pop_back();
        }

        if (closed_count < open_count) {
            group += ')';
            backtrack(n, open_count, closed_count + 1, result, group);
            group.pop_back();
        }
    }

};
