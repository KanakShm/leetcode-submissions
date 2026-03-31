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
        for (int i = 0; i < s.size(); ++i) {
            // Check odd substr
            int j = i;
            int k = i;
            while (j >= 0 && k < s.size() && 
                   s[j] == s[k]) {
                res++;
                j--;
                k++;
            }

            // Check even substr
            int l = i;
            int m = i + 1;
            while (l >= 0 && m < s.size() && 
                   s[l] == s[m]) {
                res++;
                l--;
                m++;
            }
        }
        return res;
    }
};
