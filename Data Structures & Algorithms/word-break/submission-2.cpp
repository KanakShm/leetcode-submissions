class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        Dynamic programming:
            Cache i
        
        Back Tracking:
            Choose one word out of word dictionary
            If it matches, then continue with new index
                Each time you start at new index and update if it matches
        
        Base case:
            i == s.size();
        
        he
        he
        */

        std::vector<int> dp(s.size(), -1);
        return dfs(s, wordDict, 0, dp);
    }

    bool dfs(std::string& s, std::vector<std::string>& wordDict, int i, std::vector<int>& dp) {
        if (i >= s.size()) return true;

        if (dp[i] != -1) return dp[i];

        for (int j = 0; j < wordDict.size(); ++j) {
            std::string word = wordDict[j];
            // Compare this word to the string starting from i and going until the length of 
            // the word

            if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
                if (dfs(s, wordDict, i + word.size(), dp)) {
                    dp[i] = 1;
                    return true;
                }
            }
        }

        dp[i] = 0;
        return false;
    }
};
