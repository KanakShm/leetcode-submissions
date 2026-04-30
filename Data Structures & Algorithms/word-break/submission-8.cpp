class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
            Use index as the state variable
            try and match the current index with each word in word Dict
            if a word matches recurse to that new index
            base case if i > s.size() return false
            if i == s.size() return true
            only mark dp as false after we traverse through all of word dict and find
            that none of them match
                getting from that index to the end of the string is impossible
        */

        std::vector<int> dp(s.size() + 1, -1);
        dp[s.size()] = 1;
        return dfs(s, wordDict, dp, 0);
    }

    bool isSame(std::string& s, int i, std::string& word) {
        for (int j = 0; j < word.size(); ++j) {
            if (i >= s.size() || s[i] != word[j]) return false;
            i++;
        }

        return true;
    }

    bool dfs(std::string& s, std::vector<std::string>& wordDict, std::vector<int>& dp, int i) {
        if (i > s.size()) return false;
        if (i == s.size()) return true;
        if (dp[i] != -1) return dp[i];

        for (int j = 0; j < wordDict.size(); ++j) {
            // start matching letters from s to wordDict
            if (isSame(s, i, wordDict[j]) && dfs(s, wordDict, dp, i + wordDict[j].size())) {
                dp[i] = 1;
                return true;
            }
        }

        dp[i] = 0;
        return false;
    }
};
