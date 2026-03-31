class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
            append all words to a graph hashmap
                first is word
                second is array of neighbours
                
            
            dfs from beginWord to endWord
                each call we append to intermediate array
                after each call we remove from intermediate array
                base case is if we find endword -> we append intermediate string to res
                void function

            return the res array element that has the least size
        */

        std::unordered_map<std::string, std::vector<std::string>> umap;
        for (int i = 0; i < wordList.size(); ++i) {
            umap[wordList[i]] = {};
        }

        if (umap.find(beginWord) == umap.end()) {
            wordList.push_back(beginWord);
            umap[beginWord] = {};
        }

        for (int i = 0; i < wordList.size(); ++i) {
            std::string word_a = wordList[i];
            for (int j = 0; j < wordList.size(); ++j) {
                if (i == j) continue;
                std::string word_b = wordList[j];
                int count = 0;
                for (int k = 0; k < word_a.size(); ++k) {
                    if (word_a[k] != word_b[k]) {
                        count++;
                    }
                }
                if (count == 1) {
                    umap[word_a].push_back(word_b);
                }
            }
        }

        for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
            std::cout << iter->first << ": ";
            for (int i = 0; i < iter->second.size(); ++i) {
                std::cout << iter->second[i] << " ";
            }
            std::cout << std::endl;
        }

        std::vector<std::string> inter;
        std::vector<std::vector<std::string>> res;
        std::unordered_set<std::string> visited;

        dfs(endWord, inter, res, umap, beginWord, "", visited);

        std::cout << res.size();

        int min = INT_MAX;
        for (int i = 0; i < res.size(); ++i) {
            min = std::min<int>(min, res[i].size());
        }

        return min == INT_MAX ? 0 : min + 1;
    }

    /*
    cat -> bat, fat, rat
    bat -> cat, fat, rat
    fat -> bat
    rat -> bat
    */
    void dfs(std::string& endWord, std::vector<std::string>& inter,
             std::vector<std::vector<std::string>>& res, std::unordered_map<std::string, std::vector<std::string>>& umap,
             std::string word, std::string parent, std::unordered_set<std::string>& visited)
    {
        if (visited.count(word)) {
            return;
        }

        if (word == endWord) {
            res.push_back(inter);
            return;
        }

        inter.push_back(word);
        visited.insert(word);
        std::vector<std::string> neighbours = umap[word];
        for (int i = 0; i < neighbours.size(); ++i) {
            if (neighbours[i] == parent) continue;
            dfs(endWord, inter, res, umap, neighbours[i], word, visited);
        }
        inter.pop_back();
        visited.erase(word);
    }
};
