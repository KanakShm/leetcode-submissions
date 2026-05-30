class Solution {
public:
    string reorganizeString(string s) {
        /*  
            count appearance of each letter
            push to max heap
            pop from max heap and append to queue

            queue: y
            res: bcd
            abbccdd
            b: 1
            c: 1
            a: 1

            queue: d,1
        */
        
        std::unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i]]++;
        }

        std::priority_queue<std::pair<int, char>> max_heap;
        for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
            max_heap.push({iter->second, iter->first});
        }

        std::string res;
        std::queue<std::pair<int, char>> q;
        while (!max_heap.empty()) {
            std::pair<int, char> top = max_heap.top();
            max_heap.pop();

            int frequency = top.first;
            char letter = top.second;

            res += letter;
            frequency--;

            if (!q.empty()) {
                max_heap.push(q.front());
                q.pop();
            }

            if (frequency) {
                q.push({frequency, letter});
            }
        }
        
        return q.empty() ? res : "";   
    }
};