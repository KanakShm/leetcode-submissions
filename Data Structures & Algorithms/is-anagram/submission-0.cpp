class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int n = s.size();
        for (int i = 0; i < n; ++i) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        for (int i = 0; i < n; ++i) {
            // check the number of occurrances of each key match
            if (s_map[s[i]] != t_map[s[i]]) {
                return false;
            }
        }
        return true;
    }

private:
    std::unordered_map<char, int> s_map;
    std::unordered_map<char, int> t_map;
};
