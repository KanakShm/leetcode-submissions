class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
            BFS traversal:
            Maintian a queue that contains words
            pop all elements from the queue. This ensures level processing
            only add to the queue if we see that a mutated word is contained within the dictionary
            since graph is undirected, we need to keep track of visited array or remove from the dictionary
                once we add it to the queue
        */

        std::unordered_set<std::string> dictionary(wordList.begin(), wordList.end());

        if (dictionary.find(endWord) == dictionary.end() || beginWord == endWord) {
            return 0;
        }

        std::queue<std::string> q;
        q.push(beginWord);

        int count = 0;
        while (!q.empty()) {
            count++;
            // Iterate over the entire queue length to make sure we traverse level order
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                std::string word = q.front();
                q.pop();

                if (word == endWord) return count;
                // Change each letter of the word
                for (int j = 0; j < word.size(); ++j) {
                    for (int k = 0; k < 26; ++k) {
                        std::string mutated = word;
                        mutated[j] = (char)(k + 'a');
                        if (mutated == word) continue;
                        if (dictionary.find(mutated) != dictionary.end()) {
                            q.push(mutated);
                            dictionary.erase(mutated);
                        }
                    }
                }
            }
        }
        return 0;
    }

};
