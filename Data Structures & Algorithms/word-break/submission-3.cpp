class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
            for loop through wordDict to choose each word. For each word check if it matches
            from i to the length of that word
            if it doesnt you go to the next iteration of the loop (next word)
            if it does you recurse to i + length of the word

            at each i we can store a true or false (mainly false) in a dp array 

            a a b c d e
        */

        std::vector<int> dp(s.size(), -1);
        return dfs(s, wordDict, 0, dp);
    }

    bool dfs(std::string& s, std::vector<std::string>& wordDict, int i, std::vector<int>& dp) {
        if (i == s.size()) return true;
        if (dp[i] != -1) return dp[i];

        for (int j = 0; j < wordDict.size(); ++j) {
            std::string word = wordDict[j];
            int idx = i;
            std::string s1 = "";
            while (idx < s.size() && idx < i + word.size()) {
                s1 += s[idx];
                idx++;
            }

            if (s1 == word) {
                if (dfs(s, wordDict, i + word.size(), dp)) {
                    return true;
                }
            }
        }

        dp[i] = false;
        return false;
    }
};
