class Solution {
public:
    int res = 0;
    int longestCommonSubsequence(string text1, string text2) {
        /*
            backtracking
            choose current letter move to next
            dont choose current letter
            if longer text i doesnt match shorter text i then return
            if they match add one to the count and update res
            if we get to the end of the string return 1
            have 2 indices i and j for both strings
            dfs choose + dont choose
        */
        if (text1.size() < text2.size()) 
            return longestCommonSubsequence(text2, text1);
        
        std::vector<std::vector<int>> dp(text1.size(), std::vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0, dp);
    }

    int dfs(std::string& text1, std::string& text2, int i, int j, std::vector<std::vector<int>>& dp) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + dfs(text1, text2, i + 1, j + 1, dp);
            return dp[i][j];
        } else {
            dp[i][j] = std::max(dfs(text1, text2, i, j + 1, dp), dfs(text1, text2, i + 1, j, dp));
        }

        return dp[i][j];
    }
};
