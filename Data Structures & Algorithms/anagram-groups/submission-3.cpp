class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*  Create an array of 26 elements representing the English alphabet
            create a hashmap with the key being the array that is filled with the count of
            each element
            the value will be the string itself
        */  

        std::for_each(strs.begin(), strs.end(), [&](std::string str) {
            std::vector<int> alphabets(26, 0);
            std::for_each(str.begin(), str.end(), [&](char c) {
                alphabets[static_cast<int>(c) - static_cast<int>('a')]++;
            });
            std::string alphabet_string;
            for (int i = 0; i < alphabets.size(); ++i) {
                int count = alphabets[i];
                while (count > 0) {
                    alphabet_string.push_back(static_cast<char>(i + static_cast<int>('a')));
                    count--;
                }
            }
            umap[alphabet_string].push_back(str);
        });

        std::vector<std::vector<std::string>> result;
        for (auto i = umap.begin(); i != umap.end(); ++i) {
            result.push_back(i->second);
        }

        return result;
    }

private:
    std::unordered_map<std::string, std::vector<std::string>> umap;
};