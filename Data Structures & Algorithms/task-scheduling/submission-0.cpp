class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            intuition:
            schedule identical tasks first to allow for more clock cycles
            to take place -> hashmap iterate through and construct heap

            schedule most frequent task and iterate the clock cycle
            create a max heap <count, last used>
            
            pop from the heap and add to the queue <count, last_used>
            if the current clock cycle - last_used >= 0 then re add to the heap

            O(n) o(n)

            A A A B C B
            A 3
            B 2
            C 1
        */
        std::unordered_map<char, int> umap;
        for (int i = 0; i < tasks.size(); ++i) {
            umap[tasks[i]]++;
        }

        std::vector<std::vector<int>> heap;
        for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
            heap.push_back({iter->second, 0});
            std::push_heap(heap.begin(), heap.end(), std::less<std::vector<int>>());
        }

        std::queue<std::vector<int>> q;
        int clock_cycle = 0;
        while (!heap.empty() || !q.empty()) {
            if (!heap.empty()) {
                std::vector<int> top = heap[0];
                std::pop_heap(heap.begin(), heap.end(), std::less<std::vector<int>>());
                heap.pop_back();

                top[0]--;
                top[1] = clock_cycle;

                if (top[0] > 0) {
                    q.push(top);
                }
            }

            while (!q.empty() && clock_cycle - q.front()[1] >= n) {
                heap.push_back(q.front());
                std::push_heap(heap.begin(), heap.end(), std::less<std::vector<int>>());
                q.pop();
            }
            clock_cycle++;
        }

        return clock_cycle;
    }
};
