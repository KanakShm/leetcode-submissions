class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
            Max heap:
            store all nums in a heap and then pop k times
            nlogn + klogn

            only have k elements in heap
            nlogk

            create min heap of k elements
            each iteration of nums we add to the heap and pop if the size is greater than k
            n(logk + logk)
        */ 

        std::vector<int> heap;
        for (int i = 0; i < nums.size(); ++i) {
            heap.push_back(nums[i]);
            std::push_heap(heap.begin(), heap.end(), std::greater<int>());

            if (heap.size() > k) {
                std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
                heap.pop_back();
            }
        }

        return heap[0];
    }
};
