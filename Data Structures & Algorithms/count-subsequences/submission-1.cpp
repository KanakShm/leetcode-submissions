class Solution {
public:
    int numDistinct(string s, string t) {
        /*
            Backtracking select a letter i in string s if it matches j in string t
            for loop with dfs (i + 1) and with loop starting at index i and moving to the 
            end of the string
            base case if we are at the end of the string
            return 1 if j is at the end of the string t
            return 0 if s is at the end and j is not

            Dynamic programming 2D with states i and j
            return i and j if they exist otherwise store the max number of ways from 
            that element to the end of the reutnr in the dfs
        */

        std::vector<std::vector<unsigned long long>> dp(s.size() + 1, std::vector<unsigned long long>(t.size() + 1, -1));
        return dfs(s, t, 0, 0, dp);
    }

    int dfs(std::string& s, std::string& t, int i, int j, std::vector<std::vector<unsigned long long>>& dp) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        int take = 0;
        int leave = dfs(s, t, i + 1, j, dp);
        if (s[i] == t[j]) take = dfs(s, t, i + 1, j + 1, dp);

        dp[i][j] = take + leave;
        return dp[i][j];
    }
};
