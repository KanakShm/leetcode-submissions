class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            iterate through each word letter by letter at the same time
            maintain a count
            return the count the first instance a letter doesnt match
        */

        int max_word_size = 0;
        for (int i = 0; i < strs.size(); ++i) {
            max_word_size = std::max(max_word_size, (int)strs[i].size());
        }

        std::string res;
        for (int i = 0; i < max_word_size; ++i) {
            if (i >= strs[0].size()) return res;
            char letter = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != letter) return res;
            }
            res += letter;
        }

        return res;
    }
};