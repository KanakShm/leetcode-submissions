class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    /*
        Backtracking
        iterate through the string s1, s2, s3 with i j and k
        pick the first i if it equals s3 k backtrack with i + 1
        and k + 1. Do the same with s2.
        Base case is if we are at the end of s3 and also s2 and s1
        return true.
    */
        std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, -1));
        return dfs(s1, s2, s3, 0, 0, 0, dp);
    }

    bool dfs(std::string& s1, std::string& s2, std::string& s3, int i, int j, int k, std::vector<std::vector<int>>& dp) {
        if (k == s3.size()) {
            return i == s1.size() && j == s2.size();
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (i < s1.size() && s1[i] == s3[k]) {
            if (dfs(s1, s2, s3, i + 1, j, k + 1, dp)) {
                dp[i][j] = true;
                return true;
            }
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            if (dfs(s1, s2, s3, i, j + 1, k + 1, dp)) {
                dp[i][j] = true;
                return true;
            }
        }

        dp[i][j] = false;
        return false;
    }
};
