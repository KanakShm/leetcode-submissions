class Solution {
public:
    string minWindow(string s, string t) {
        /*
            store string t in a hashmap
            move left and right forward until we hit the frst letter
            only move right forward until we have the full string t
                and the frequency of each letter matches
            shrink left until we drop a letter and the frequencies dont
            match again then grow right
            save the min size result each iteration of left
        */

        std::unordered_map<char, int> t_count;
        std::unordered_map<char, int> s_count;
        for (int i = 0; i < t.size(); ++i) {
            t_count[t[i]]++;
        }

        int left = 0;
        int right = 0;

        int left_res = -9999;
        int right_res = 9999;
        while (right < s.size()) {
            s_count[s[right]]++;

            // iterate through t_count and see if all the frequencies match
            bool is_substr = true;
            for (auto iter = t_count.begin(); iter != t_count.end(); ++iter) {
                if (iter->second > s_count[iter->first]) is_substr = false;
            }

            // while it is a substr, increment the left pointer
            while (left < s.size() && is_substr) {
                if (right - left + 1 < right_res - left_res + 1) {
                    right_res = right;
                    left_res = left;
                }

                s_count[s[left]]--;
                for (auto iter = t_count.begin(); iter != t_count.end(); ++iter) {
                    if (iter->second > s_count[iter->first]) is_substr = false;
                }
                left++;
            }

            right++;
        }

        if (left_res == -9999 && right_res == 9999) {
            return "";
        }

        std::string res;
        while (left_res <= right_res) {
            res += s[left_res];
            left_res++;
        }

        return res;
    }
};
