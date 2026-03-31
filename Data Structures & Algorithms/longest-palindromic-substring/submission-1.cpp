class Solution {
public:
    string longestPalindrome(string s) {
        /*
            2D dynamic programming:
            initialise an array of bools and set them to false

            iterate from the end of the string in a double for loop
            use i as left pointer and j as right pointer

            always ask if i to j is a palendrome and if it is fill dp[i][j] with true
            i and j will be a palendrome if s[i] == s[j] and also if i + i and j - 1 is true in the
            dp table

            base cases if i == j and if j - i == 0 or 1 and if dp table is also true

            start at the end so we have i + 1 and j - 1 already filled out as we iterate
        */
        int max_size = 0;
        int start = 0;
        int end = 0;
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (max_size <= j - i + 1) {
                        max_size = j - i + 1;
                        start = i;
                        end = j;
                    }
                }
            }
        }
        std::cout << end;
        std::string output;
        while (start <= end) {
            output += s[start];
            start++;
        }
        return output;
    }
};
