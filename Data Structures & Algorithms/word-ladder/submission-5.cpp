class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
            bfs for minimum number of words
            create an adjacency list of all words from word list
            each word in word list consists of all combinations of that word
                one off
            
            we iterate through this list and only add to the queue if it appears
            in the word list

            if the begin word matches the end word we return the count
            every time we pop from queue we pop everything at once to ensure we
            travel in layers
        */

        std::unordered_map<std::string, std::vector<std::string>> adj_list;
        for (int i = 0; i < wordList.size(); ++i) {
            adj_list[wordList[i]] = {};
        }

        if (adj_list.find(beginWord) == adj_list.end()) {
            adj_list[beginWord] = {};
            wordList.push_back(beginWord);
        }

        for (int i = 0; i < wordList.size(); ++i) {
            std::string word = wordList[i];
            for (int j = 0; j < word.size(); ++j) {
                std::string new_word = word;
                for (int k = 0; k < 26; ++k) {
                    new_word[j] = 'a' + k;
                    if (word != new_word) {
                        adj_list[word].push_back(new_word);
                    }
                }
            }
        }

        std::unordered_set<std::string> visited;
        std::queue<std::string> q;
        q.push(beginWord);
        int min_number = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                std::string word = q.front();
                q.pop();

                if (word == endWord) return min_number;

                std::vector<std::string> neighbours = adj_list[word];

                for (int j = 0; j < neighbours.size(); ++j) { 
                    if (!visited.count(neighbours[j]) && adj_list.find(neighbours[j]) != adj_list.end()) {
                        visited.insert(neighbours[j]);
                        q.push(neighbours[j]);
                    }
                }
            }
            min_number++;
        }

        return 0;
    }
};
