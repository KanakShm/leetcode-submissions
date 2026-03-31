class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a hashmap with the sorted string as your key and the value being
        // a vector of strings that have the same sorted string (anagram)
        std::for_each(strs.begin(), strs.end(), [&](std::string str) {
            std::string ordered = str;
            std::sort(ordered.begin(), ordered.end());
            umap[ordered].push_back(str);
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