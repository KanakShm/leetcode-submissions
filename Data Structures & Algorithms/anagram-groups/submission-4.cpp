class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
            hashmap that links the anagram with a vector of words
            go through the list and create an anagram word
                array of 26 elements where each index represents the count
                of the leter
                this is the key
            once we build the key see if it exists in the hashmap
            if it does append the current word to it or make a new key and append
            the current word
        */    

        std::unordered_map<std::string, std::vector<std::string>> anagrams;
        for (int i = 0; i < strs.size(); ++i) {
            std::array<int, 26> current_anagram;
            current_anagram.fill(0);
            for (int j = 0; j < strs[i].size(); ++j) {
                int idx = strs[i][j] - 'a';
                current_anagram[idx]++;
            }

            std::string current_anagram_string;
            for (int j = 0; j < current_anagram.size(); ++j) {
                current_anagram_string = current_anagram_string + "," + std::to_string(current_anagram[j]);
            }
            anagrams[current_anagram_string].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> res;
        for (auto iter = anagrams.begin(); iter != anagrams.end(); ++iter) {
            res.push_back(iter->second);
        }

        return res;
    }
};  