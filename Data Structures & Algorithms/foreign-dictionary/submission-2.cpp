class Solution {
public:
    std::unordered_map<char, std::unordered_set<char>> adj_list;
    std::unordered_set<char> visited;
    std::string res;
    string foreignDictionary(vector<string>& words) {
        /*
            Use two pointers to iterate through two adjacent words
            at a time.
            Iterate character by character
            If a character differs then add the first character to the
            hashmap with the second character being the value
            this way we create a lot of trees. Then our job is just to 
            append these together using a visited set

            apple appel lop fop
            l->e
            a->l
            l->f
        */
        if (words.size() <= 1) return words[0];
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                adj_list[words[i][j]] = {};
            }
        }

        int left = 0, right = 1;
        while (right < words.size()) {
            std::string a = words[left];
            std::string b = words[right];

            int i = 0, j = 0;
            while (i < a.size() && j < b.size() && a[i] == b[j]) {
                i++;
                j++;
            }

            if (i != a.size() && j != b.size()) {
                adj_list[a[i]].insert(b[j]);
            } else if (i != a.size() && j == b.size()) {
                return "";
            }

            left++;
            right++;
        }

        for (auto iter = adj_list.begin(); iter != adj_list.end(); ++iter) {
            std::unordered_set<char> path;
            if (!visited.count(iter->first) && !dfs(iter->first, path)) return "";
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char letter, std::unordered_set<char>& path) {
        if (path.count(letter)) return false;

        path.insert(letter);
        std::unordered_set<char> connections = adj_list[letter];
        for (auto iter = connections.begin(); iter != connections.end(); ++iter) {
            if (!visited.count(*iter) && !dfs(*iter, path)) return false;
        }

        visited.insert(letter);

        path.erase(letter);
        res.push_back(letter);
        return true;
    }
};
