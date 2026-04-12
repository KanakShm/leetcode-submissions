class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        /*
            sort the queries and process them in ascending order with their index in the second element
            pointer to intervals and push to heap while the query is greater than or equal to the start 
            time
                this is to get the all the intervals that start before or after the current query
                pop from the heap until one has the range that encompasses the query
            
            min-heap <size, interval>

            sort it back in order O(n) and return
        */

        std::vector<std::vector<int>> sorted_queries;
        for (int i = 0; i < queries.size(); ++i) {
            sorted_queries.push_back({queries[i], i});
        }

        std::sort(sorted_queries.begin(), sorted_queries.end(), std::less<std::vector<int>>());
        std::sort(intervals.begin(), intervals.end(), std::less<std::vector<int>>());
        
        std::vector<std::pair<int, std::vector<int>>> interval_heap;
        std::vector<int> output(queries.size(), -1);

        int idx = 0;
        for (int i = 0; i < sorted_queries.size(); ++i) {
            // While the start is less than or equal to the current query
            while (idx < intervals.size() && sorted_queries[i][0] >= intervals[idx][0]) {
                int size = intervals[idx][1] - intervals[idx][0] + 1;
                interval_heap.push_back(std::make_pair(size, intervals[idx]));
                std::push_heap(interval_heap.begin(), interval_heap.end(), std::greater<>());
                idx++;
            }

            while (!interval_heap.empty() && interval_heap.front().second[1] < sorted_queries[i][0]) {
                std::pop_heap(interval_heap.begin(), interval_heap.end(), std::greater<>());
                interval_heap.pop_back();
            }

            if (!interval_heap.empty()) {
                output[sorted_queries[i][1]] = interval_heap.front().first;
            }
        }

        return output;
    }
};
