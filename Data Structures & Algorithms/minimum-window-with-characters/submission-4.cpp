class Solution {
public:
    string minWindow(string s, string t) {
        /*
            left and right pointer at 0
            increment right pointer all the way until we have all elements in t
            helper function for seeing if all elements in t are present
            if they are then increment l and get rid of it in hashmap
            if they are not then increment r and add to hashmap
        */

        std::unordered_map<char, int> count1;
        for (int i = 0; i < t.size(); ++i) {
            count1[t[i]]++;
        }

        std::unordered_map<char, int> count2;
        int left_res = -99999;
        int right_res = 99999;
        int left = 0;
        int right = 0;
        while (left < s.size()) {
            while (right < s.size() && !hasSubstr(count1, count2)) {
                count2[s[right]]++;
                right++;
            }

            if (hasSubstr(count1, count2) && right - left < right_res - left_res) {
                right_res = right;
                left_res = left;
            }

            count2[s[left]]--;
            left++;
        }

        std::string res = "";
        while (left_res -99999 && right_res != 99999 && left_res < right_res) {
            res += s[left_res];
            left_res++;
        }

        return res;
    }

    bool hasSubstr(std::unordered_map<char, int>& count1, std::unordered_map<char, int>& count2) {
        for (auto iter = count1.begin(); iter != count1.end(); ++iter) {
            if (count2[iter->first] < iter->second) return false;
        }

        return true;
    }
};
