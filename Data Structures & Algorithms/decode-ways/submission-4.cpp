class Solution {
public:
    int numDecodings(string s) {
        /*
            Backtracking:
                choose one number, recurse to i + 1
                choose two numbers i and i + 1

            Memoisation:
                cache updates the count before we return from each dfs
                the index contains the number of ways if we choose the current index
                    + if we choose the current and the next
        */
        std::vector<int> dp(s.size(), -1);
        return dfs(s, 0, dp);
    }

    int dfs(std::string& s, int i, std::vector<int>& dp) {
        if (i >= s.size()) return 1;

        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];
        
        // Choose one number
        int res = dfs(s, i + 1, dp);

        // Choose two numbers
        if (i + 1 < s.size()) {
            int number = (s[i] - '0') * 10 + s[i + 1] - '0';
            if (number > 0 && number <= 26) {
                res += dfs(s, i + 2, dp);
            }
        }

        dp[i] = res;
        return dp[i];
    }
};
