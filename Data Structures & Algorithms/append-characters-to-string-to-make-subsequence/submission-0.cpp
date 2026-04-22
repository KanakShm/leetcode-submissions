class Solution {
public:
    int appendCharacters(string s, string t) {
        /*
            iterate through both strings until s[i] != t[i]
            maintain two pointers at s and t
            always iterate s
            only iterate t when character s = character t
            when we reach the end of s, we need to append t.size() - t + 1 characters

            i = 2
            j = 2
            coaching
            coding
        */

        int i = 0;
        int j = 0;

        while (i < s.size()) {
            if (s[i] == t[j]) j++;
            i++;
        }

        return t.size() - j;
    }
};