class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        /*
            Maintain internal time variable
            heap: processing time (process time), index
                when you pop from heap the time increments to
                curr += process time
            
            first value is when the task can be processed
            two heaps -> one to track which task to process
            one to track which process gets put on the processing heap
            push enque heap curr time + enqueu time
                only pop if current time is >= enqueu time
                then push that element on the process heap

            if there are elements on the processing heap then pop one element
            and increment time += how long it took. Get rid of all the elements 
            that need processing. We will then be some distance into the future
            so keep popping from the enqueu heap.
        */
        std::vector<int> res;
        long long time = 0;
        std::priority_queue<std::pair<long long, int>> enqueue;
        for (int i = 0; i < tasks.size(); ++i) {
            enqueue.push(std::make_pair(-tasks[i][0], -i));
        }

        std::priority_queue<std::pair<long long, int>> process;
        while (!enqueue.empty() || !process.empty()) {
            if (time > enqueue.top().first) {
                time = enqueue.top().first;
            }
            while (!enqueue.empty() && enqueue.top().first >= time) {
                std::pair<long long, int> top = enqueue.top();
                enqueue.pop();
                process.push(std::make_pair(-tasks[-top.second][1], top.second));
            }

            if (!process.empty()) {
                std::pair<long long, int> top = process.top();
                process.pop();
                res.push_back(-top.second);
                time += top.first;
            }
        }

        return res;
    }
};