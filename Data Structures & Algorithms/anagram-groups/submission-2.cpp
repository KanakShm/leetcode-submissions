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
            map[alphabets].push_back(str);
        });

        std::vector<std::vector<std::string>> result;
        for (auto i = map.begin(); i != map.end(); ++i) {
            result.push_back(i->second);
        }

        return result;
    }

private:
    std::map<std::vector<int>, std::vector<std::string>> map;
};