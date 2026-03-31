#include <array>

class Solution {
public:
    std::array<std::vector<char>, 8> letters = {{
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    }};
    vector<string> letterCombinations(string digits) {
        /*
            for every digit we will index into the array and run a for loop
            each iteration of the for loop we will append to a local string
            backtrack with digit[i+1]
            base case is if i == digit size
        */
        std::vector<std::string> res;
        std::string str;
        backtrack(0, res, str, digits);
        return res;
    }

    void backtrack(int i, std::vector<std::string>& res, std::string& str, std::string digits) {
        if (i == digits.size()) {
            if (digits.size() > 0 && str.size() == digits.size()) {
                res.push_back(str);
            }
            return;
        }

        // for loop over to get each of the digits and then backtrack
        for (int j = i; j < digits.size(); ++j) {
            int idx = static_cast<int>(digits[j] - '0') - 2;
            for (int k = 0; k < letters[idx].size(); ++k) {
                str += letters[idx][k];
                backtrack(j + 1, res, str, digits);
                str.pop_back();
            }
        }
    }
};
