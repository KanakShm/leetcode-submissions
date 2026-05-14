class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
        Does the current letter equal on both strings
            Is the previous letter equal on both strings
              M O N E Y
            t f f f f f
        M   f t f f f f
        O   f f t f f f
        N   f f f t f f
        K   f f f 
        E
        Y

        abc abcd

        backtracking
        at each i and j if they match increment both indices
        if they differ then dfs by 
            inserting -> 1 + dfs(i, j + 1)
            deleting  -> 1 + dfs(i + 1, j)
            replacing -> 1 + dfs(i + 1, j + 1)

        base case: if we are at the end of word 1 return 0
        Then return the min of all 3 results

        Dynamic programming:
        Since we return the min of all three options, the state only depends
        on where i and j are. 2D DP table for optimisation

        abc edfgg
        4
        */

        std::vector<std::vector<int>> dp(word1.size(), std::vector<int>(word2.size(), -1));
        return dfs(word1, word2, dp, 0, 0);
    }

    int dfs(std::string& word1, std::string& word2, std::vector<std::vector<int>>& dp, int i, int j) {
        if (i == word1.size() && j == word2.size()) return 0;
        if (i == word1.size() && j != word2.size()) return word2.size() - j;
        if (i != word1.size() && j == word2.size()) return word1.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        int min_replacements = 0;
        if (word1[i] != word2[j]) {
            int insert = 1 + dfs(word1, word2, dp, i, j + 1);
            int del = 1 + dfs(word1, word2, dp, i + 1, j);
            int replace = 1 + dfs(word1, word2, dp, i + 1, j + 1);
            min_replacements = std::min(std::min(insert, del), replace);
        } else {
            min_replacements = dfs(word1, word2, dp, i + 1, j + 1);
        }

        dp[i][j] = min_replacements;
        return min_replacements;
    }
};
