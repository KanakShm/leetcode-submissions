class KthLargest {
public:
/*
    initialise min-heap with k elements
    when you add, push the heap and get the top value (should be the lowest)
    
    idea is the heap will contain k elements, with the smallest of the k (kth largest) at
    the first index. Any addition will update the heap in log n

    Each time we add to the heap we pop the smallest element to maintain size k

    4 5 8 2
    2 3 3 5
*/
    KthLargest(int k, vector<int>& nums) : m_k(k) {
        for (int i = 0; i < nums.size(); ++i) {
            heap.push_back(nums[i]);
            std::push_heap(heap.begin(), heap.end(), std::greater<int>());
        }

        while (heap.size() > m_k) {
            std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
            heap.pop_back();
        }
    }
    
    int add(int val) {
        heap.push_back(val);
        std::push_heap(heap.begin(), heap.end(), std::greater<int>());

        if (heap.size() > m_k) {
            std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
            heap.pop_back();
        }
        return heap[0];
    }

    std::vector<int> heap;
    int m_k;
};
