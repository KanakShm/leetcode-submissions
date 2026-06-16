class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            sliding window 
            hashset to store characters
            increment right if we see a duplicate increment left until we drop that letter

            zxyzxyz
            zxy
        */
        if (s.empty()) return 0;
        std::unordered_set<char> substring;
        int left = 0;
        int right = 0;

        substring.insert(s[right]);
        right++;

        int res = 1;
        while (right < s.size()) {
            while (substring.count(s[right])) {
                substring.erase(s[left]);
                left++;
            }

            substring.insert(s[right]);
            res = std::max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
