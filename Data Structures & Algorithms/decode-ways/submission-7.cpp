class Solution {
public:
    int numDecodings(string s) {
        /*
            10 1 2
            10 12

            backtracking -> choose the first element then choose two elements
            1 0
            if we see 0 then return
            if we choose 2 and the number is > 26 return

            increase the number of ways when we reach the end of the string
            at each i, store how many ways to get to the end of string
            (i + 1) + (i + 2)

            dp array with s.size() + 1 characters. When we get to the end we return 
            0 and we dfs with 1 + dfs()
        */

        std::vector<int> dp(s.size() + 1, -1);
        return dfs(s, dp, 0);
    }

    int dfs(std::string& s, std::vector<int>& dp, int i) {
        if (i == s.size()) return 1;
        if (i > s.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int ways = 0;
        // Pick one element
        int one_digit = s[i] - '0';
        if (one_digit == 0) return 0;
        ways += dfs(s, dp, i + 1);

        // Pick two elements
        if (i + 1 < s.size()) {
            one_digit *= 10;
            int two_digit = one_digit + (s[i + 1] - '0');
            if (two_digit > 26) return ways;
            ways += dfs(s, dp, i + 2);
        }

        dp[i] = ways;
        return ways;
    }
};
