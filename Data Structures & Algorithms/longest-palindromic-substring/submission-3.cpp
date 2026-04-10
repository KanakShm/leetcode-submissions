class Solution {
public:
    string longestPalindrome(string s) {
        /*
            brute force
            increase the window size and at each iteration we check if the string is 
            a palendrome
            o(n^3)

            sliding window doesnt work: abcgggggcba
            start out at the middle and grow left and right

            iterate over the whole array and treat i as the centre
            expand outwards and modify the longest palendrome if it is
            sliding window O(n^2)

            baab
        */
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            // Odd length strings
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > end - start + 1) {
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }

            // Even lengths strings 
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (right - left + 1 > end - start + 1) {
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }
        }

        std::string res = "";
        while (start <= end) {
            res.push_back(s[start]);
            start++;
        }

        return res;
    }
};
