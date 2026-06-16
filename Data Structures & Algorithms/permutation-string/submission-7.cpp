class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            put all frequency of s1 in hashmap
            have a left and right pointer
            if frequency of right in s2 < frequency of right in s1
                add to s2 map
            else increment left and reduce the count of left in s2 map
            after check the map and if all frequencies match, then return true
            return false after while loop

            abc
            lecabee
        */

        std::unordered_map<char, int> freq1;
        std::unordered_map<char, int> freq2;

        for (int i = 0; i < s1.size(); ++i) {
            freq1[s1[i]]++;
        }

        int left = 0;
        int right = 0;
        while (right < s2.size()) {
            if (freq1.find(s2[right]) != freq1.end()) {
                if (freq1[s2[right]] > freq2[s2[right]]) {
                    freq2[s2[right]]++;
                    right++;
                } else {
                    freq2[s2[left]]--;
                    left++;
                }
            } else {
                right++;
                while (left < right) {
                    freq2[s2[left]]--;
                    left++;
                }
            }

            if (right - left == s1.size()) return true;
        }

        return false;
    }
};
