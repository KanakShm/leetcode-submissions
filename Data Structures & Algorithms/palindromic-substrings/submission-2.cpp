class Solution {
public:
    int countSubstrings(string s) {
        /*
        Dynamic Programming:
        Palendrome if s[i] = s[j] and dp[i + 1][j - 1] is also a palendrome;
        start i from the end
        start j from i and iterate up

        2 pointers:
            i and j pointers
            start j at i to capture odd strings
            if i - j is even string has odd number of letters
                check if s[i] = s[j] then move pointers outwards one space
                add one to the total if they are equal
            
            start at j = i + 1 to capture even strings
        */
        int res = 0;
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {
                        dp[i][j] = true;
                        res++;
                    }
            }
        }
        return res;
    }
};
