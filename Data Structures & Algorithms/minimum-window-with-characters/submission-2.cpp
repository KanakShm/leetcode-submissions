#include <array>
class Solution {
public:
    bool arrayContains(std::unordered_map<char, int>& arr_s, std::unordered_map<char, int>& arr_t) {
        for (auto iter = arr_t.begin(); iter != arr_t.end(); iter++) {
            if (arr_s.find(iter->first) == arr_s.end() || arr_s[iter->first] < iter->second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        /*
            create a hash of string t
            left and right pointer for s
            have an array of 52 elements a-z A-Z
            iterate s with left and right pointers
            we keep incrementing right pointer until all elements exist in substring
            increment left pointer up until the first element leaves substring
            then increment right pointer forward and repeat this process.
        */ 

        std::unordered_map<char, int> arr_s;
        std::unordered_map<char, int> arr_t;
        for (int i = 0; i < t.size(); ++i) {
            arr_t[t[i]]++;
        }

        int left = 0;
        int right = 0;
        std::string output = "";
        std::array<int, 2> res = {0,0};
        while (right < s.size()) {
            std::cout << s[left] << " " << s[right] << std::endl;

            if (!arrayContains(arr_s, arr_t)) {
                arr_s[s[right]]++;
                right++;
            }
            // iterate until we have the two arrays equal

            /*
            ADOBECODEBANC
            */
            while (arrayContains(arr_s, arr_t)) {
                if (res[1] - res[0] > right - left || (res[1] == 0 && res[0] == 0)) {
                    res[0] = left;
                    res[1] = right;
                }
                arr_s[s[left]]--;
                if (arr_s[s[left]] == 0) arr_s.erase(s[left]);
                left++;
            }
        }
        for (int i = res[0]; i < res[1]; ++i) {
            output += s[i];
        }
        return output;
    }
};
