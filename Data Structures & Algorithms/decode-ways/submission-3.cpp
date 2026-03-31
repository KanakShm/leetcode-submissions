class Solution {
public:
    std::vector<int> cache;
    int numDecodings(string s) {
        /*
            decode the string to a number
            10126

            Decision tree:
            Either take one digit or two digits (if under equal 26)

            Base case:
            invalid then return false
            valid return true and add to res

            dfs:
            dfs with one digit
            dfs with two digits
            res is global variable

            memoisation:
            get to the final backtrack call
            cache number of ways to decode
            last digit will be one
            second last will be how many to get to the last plus the last

            how many ways to get to dp[i + 1] and dp[i + 2]
        */
        int res = 0;
        cache.resize(s.size(), -1);
        return dfs(s, 0);
    }

    int dfs(std::string& s, int i) {
        if (i >= s.size()) {
            return 1;
        }

        if (cache[i] != -1) return cache[i];

        if (s[i] == '0') {
            return 0;
        }      
        int first = dfs(s, i + 1);

        int second = 0;
        if (i + 1 < s.size() && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26) {
            second = dfs(s, i + 2);
        }
        
        cache[i] = first + second;
        return cache[i];
    }
};
