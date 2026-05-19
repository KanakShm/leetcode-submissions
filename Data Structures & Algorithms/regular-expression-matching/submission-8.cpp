class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            iterate each string with i and j
            if we see . we progress both i and j
            if we see a mismatch we return false
            if we see *
                
            nnnnnn
            nn
            n*nnnn

            n

            two choices,
            dfs with not elements and increment j
            take the last element and dfs with j constant 
            if i and j are not at the end and expression return false
            bubble up true if i and j are at the end

            dp with i and j
        */

        return dfs(s, p, 0, 0);
    }

    bool dfs(std::string& s, std::string& p, int i, int j) {
        if (i == s.size() && j == p.size()) return true;
        if (i != s.size() && j == p.size()) return false;
        
        bool match = ((i < s.size() && j < p.size()) && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < p.size() && p[j + 1] == '*') {
            if (dfs(s, p, i, j + 2)) return true;
            if (match && dfs(s, p, i + 1, j)) return true;
        } else if (match) {
            if (dfs(s, p, i + 1, j + 1)) return true;
        }
    
        return false;
    }
};
