class Solution {
public:
    int numDecodings(string s) {
        /*
            decode the string to a number
            10126

            Decision tree:
            Either take one digit or two digits (if under equal 26)

            Base case:
            invalid then return false
            valid return true and add to res

            dfs:
            dfs with one digit
            dfs with two digits
            res is global variable

            memoisation:
            get to the final backtrack call
            cache number of ways to decode
            last digit will be one
            second last will be how many to get to the last plus the last

            how many ways to get to dp[i + 1] and dp[i + 2]
        */
        int res = 0;
        bool search = dfs(s, res, 0);
        return res;
    }

    bool dfs(std::string& s, int& res, int i) {
        if (i == s.size()) {
            res++;
            return true;
        }

        if (i > s.size()) {
            return true;
        }

        if (s[i] == '0') return false;

        // Pick one
        dfs(s, res, i + 1);

        // Pick two
        std::string two;
        if (i + 1 < s.size()) {
            two += s[i];
            two += s[i + 1];
        }

        if ((two[0] - '0') * 10 + two[1] - '0' > 26) {
            return false;
        }

        dfs(s, res, i + 2);

        return true;
    }
};
