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
        std::string current = "";
        while (right < s.size()) {
            std::cout << current << " " << s[left] << " " << s[right] << std::endl;

            if (!arrayContains(arr_s, arr_t)) {
                arr_s[s[right]]++;
                current += s[right];
                right++;
            }
            // iterate until we have the two arrays equal

            /*
            ADOBECODEBANC
            */
            while (arrayContains(arr_s, arr_t)) {
                if (current.size() < output.size() || output.size() == 0) output = current;
                arr_s[s[left]]--;
                if (arr_s[s[left]] == 0) arr_s.erase(s[left]);
                current = current.erase(0, 1);
                left++;
            }
        }
        return output;
    }
};
