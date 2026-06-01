class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /*
            can only pick k projects
            pick the project that has the most profit and has capital
            less than or equal to current capital

            sort profit and capital arrays
            initiate a pointer that starts left and add each value to max
            heap until the capital needed > current capital

            then pop from heap and iterate left pointer up until needed > current
            do the loop k times

            nlogn + nlogn

            if cap is the same then sort decreasing profits
            cap = 2 3 3 4 4
            pro = 1 5 3 3 2
            11
            1
        */
        std::vector<std::pair<int, int>> sorted_capital;
        for (int i = 0; i < capital.size(); ++i) {
            sorted_capital.push_back({capital[i], i});
        }

        std::sort(sorted_capital.begin(), sorted_capital.end());
        std::priority_queue<std::pair<int, int>> max_heap;
        int idx = 0;
        while (k) {
            // iterate until curr capital < needed capital
            while (idx < sorted_capital.size() && sorted_capital[idx].first <= w) {
                max_heap.push({profits[sorted_capital[idx].second], sorted_capital[idx].first});
                idx++;
            }

            if (!max_heap.empty()) {
                std::pair<int, int> top = max_heap.top();
                max_heap.pop();
                w += top.first;
            }
            k--;
        }

        return w;
    }
};