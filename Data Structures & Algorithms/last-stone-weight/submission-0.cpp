class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        /*
            fix stones in a max heap
            get max twice
            pop both and update list according to winner
            push heap

            while stone size > 1
        */

        std::vector<int> heap;
        for (int i = 0; i < stones.size(); ++i) {
            heap.push_back(stones[i]);
            std::push_heap(heap.begin(), heap.end(), std::less<int>());
        }

        while (heap.size() > 1) {
            int x = heap[0];
            std::pop_heap(heap.begin(), heap.end(), std::less<int>());
            heap.pop_back();

            int y = heap[0];
            std::pop_heap(heap.begin(), heap.end(), std::less<int>());
            heap.pop_back();

            if (x > y) {
                heap.push_back(x - y);
                std::push_heap(heap.begin(), heap.end(), std::less<int>());   
            } else if (y > x) {
                heap.push_back(y - x);
                std::push_heap(heap.begin(), heap.end(), std::less<int>());
            }
        }

        if (heap.empty()) return 0;
        return heap[0];
    }
};
