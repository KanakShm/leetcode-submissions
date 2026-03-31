class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Sort all the words in the string
        // Compare
        std::vector<std::string> sorted_strs;
        std::for_each(strs.begin(), strs.end(), [&](std::string str) {
            std::string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            sorted_strs.push_back(sorted_str);
        });

        std::vector<std::vector<std::string>> result;
        std::vector<bool> visited(sorted_strs.size(), false);
        for (int i = 0; i < sorted_strs.size(); ++i) {
            std::cout << std::endl;
            if (visited[i]) continue;

            std::vector<std::string> anagram;
            anagram.push_back(strs[i]);
            visited[i] = true;

            for (int j = 0; j < sorted_strs.size(); ++j) {
                if (j != i && sorted_strs[i] == sorted_strs[j] && !visited[j]) {
                    visited[j] = true;
                    anagram.push_back(strs[j]);
                }
            }
            result.push_back(anagram);
        }
        return result;
    }
};
