class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            schedule tasks by most frequent first -> max heap
            iterate through tasks and increment a counter in 26 element
            array

            iterate through this array and push to a max heap with all 
            timestamps set to INT MIN heap -> <frequency, timestamp>
            initialise timestamp to 0

            while the heap or the queue is not empty, pop from the heap and
            decrement frequency by one and push to queue if it isnt 0

            pop element from the queue if the curr time - timestamp > n
        */

        std::vector<int> task_frequencies(26, 0);
        for (int i = 0; i < tasks.size(); ++i) {
            task_frequencies[tasks[i] - 'A']++;
        }
        
        std::vector<std::pair<int, int>> tasks_heap;
        for (int i = 0; i < task_frequencies.size(); ++i) {
            if (task_frequencies[i] == 0) continue;
            std::pair<int, int> task = std::make_pair(task_frequencies[i], INT_MIN);
            tasks_heap.push_back(task);
            std::push_heap(tasks_heap.begin(), tasks_heap.end(), std::less<>());
        }

        std::queue<std::pair<int, int>> q;
        int time = 0;
        while (!tasks_heap.empty() || !q.empty()) {
            // pop the task from the heap and push into queue
            if (!tasks_heap.empty()) {
                std::pair<int, int> task = tasks_heap.front();
                std::pop_heap(tasks_heap.begin(), tasks_heap.end(), std::less<>());
                tasks_heap.pop_back();
                
                task.first--;
                task.second = time;

                if (task.first > 0) {
                    q.push(task);
                }
            }

            time++;

            if (!q.empty() && time - q.front().second > n) {
                tasks_heap.push_back(q.front());
                std::push_heap(tasks_heap.begin(), tasks_heap.end(), std::less<>());
                q.pop();
            }
        }

        return time;
    }
};
