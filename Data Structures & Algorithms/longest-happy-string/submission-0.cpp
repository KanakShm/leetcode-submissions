class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        /*
            put all elements in a heap
            max heap <count, consecutively used count, letter>
            if con used count == 3 then put into queue for a timeout
                and reset consectivve count to 0
        */

        std::priority_queue<std::tuple<int, int, char>> max_heap;
        max_heap.push(std::make_tuple(a, 0, 'a'));
        max_heap.push(std::make_tuple(b, 0, 'b'));
        max_heap.push(std::make_tuple(c, 0, 'c'));

        std::queue<std::tuple<int, int, char>> q;
        std::string res;
        while (!max_heap.empty()) {
            std::tuple<int, int, char> top = max_heap.top();
            max_heap.pop();

            int count = get<0>(top);
            int consecutive = get<1>(top);
            char letter = get<2>(top);

            if (res.back() == letter) {
                consecutive++;
            } else {
                consecutive = 0;
            }
            
            while (!q.empty()) {
                max_heap.push(q.front());
                q.pop();
            }

            if (consecutive >= 2) {
                q.push(std::make_tuple(count, consecutive, letter));
            } else if (count) {
                res.push_back(letter);
                max_heap.push(std::make_tuple(count - 1, consecutive, letter));
            }
        }

        
        return res;
    }
};