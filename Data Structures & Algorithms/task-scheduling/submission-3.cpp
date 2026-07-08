class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            Do the most recurring task first then append to a queue
            max heap <character, frequency>
            queue<character, frequency, last_used>
            poll curr time - last used > n then pop from queue and add back to the heap
            res updates at each iteration of while loop
        */

        std::unordered_map<char, int> count;
        for (int i = 0; i < tasks.size(); ++i) {
            count[tasks[i]]++;
        }

        std::priority_queue<std::pair<int, char>> max_heap;
        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            max_heap.push({iter->second, iter->first});
        }

        int time = 0;
        std::queue<std::pair<char, std::vector<int>>> q;
        while (!max_heap.empty() || !q.empty()) {
            if (!max_heap.empty()) {
                std::pair<int, char> task = max_heap.top();
                max_heap.pop();

                if (task.first - 1 > 0)
                    q.push({task.second, {task.first - 1, time}});
            }

            time++;

            while (!q.empty() && time - q.front().second[1] > n) {
                max_heap.push({q.front().second[0], q.front().first});
                q.pop();
            }
        }

        return time;
    }
};
