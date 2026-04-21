class Solution {
public:
    std::vector<std::vector<std::string>> res;
    vector<vector<string>> partition(string s) {
        /*
            partition string into subsets
            each subset is a palindrome
            backtracking
            dfs(i + 1) for j = i
            pick the letter, pick the next couple letters
            a a b -> i == size backtrack to a
            a ab -> backtrack
            aa b -> append
            aab
            every for loop we pick the current element plus j into our
            substring, dfs i + length only if the current substring is a palindrome
                otherwise return
            
            keep track of running palindrome array and only push to res if there is a
            palindrome
        */
        std::vector<std::string> palindromes;
        dfs(s, 0, palindromes);
        return res;
    }

    bool isPalindrome(std::string& word) {
        int l = 0;
        int r = word.size() - 1;
        while (l <= r) {
            if (word[l] != word[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void dfs(std::string& s, int i, std::vector<std::string>& palindromes) {
        if (i >= s.size()) {
            res.push_back(palindromes);
        }

        for (int j = i; j < s.size(); ++j) {
            std::string word = s.substr(i, j - i + 1);
            if (isPalindrome(word)) {
                palindromes.push_back(word);
                dfs(s, j + 1, palindromes);
                palindromes.pop_back();
            }
        }
    }
};
