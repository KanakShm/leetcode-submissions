class MedianFinder {
public:
    /*
        Add to the max heap first
        check if the top element of max heap is greater than the top element of min heap
            transfer that element over if it is
        
        check if heaps sizes differ by more than 1,
            trnsfer a number over if they do 
    */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push_back(num);
        std::push_heap(max_heap.begin(), max_heap.end(), std::less<int>());

        if (!min_heap.empty() && max_heap[0] > min_heap[0]) {
            int transfer = max_heap[0];
            std::pop_heap(max_heap.begin(), max_heap.end(), std::less<int>());
            max_heap.pop_back();

            min_heap.push_back(transfer);
            std::push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
        }

        if (min_heap.size() > max_heap.size() + 1) {
            int transfer = min_heap[0];
            std::pop_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
            min_heap.pop_back();

            max_heap.push_back(transfer);
            std::push_heap(max_heap.begin(), max_heap.end(), std::less<int>());
        }

        if (max_heap.size() > min_heap.size() + 1) {
            int transfer = max_heap[0];
            std::pop_heap(max_heap.begin(), max_heap.end(), std::less<int>());
            max_heap.pop_back();

            min_heap.push_back(transfer);
            std::push_heap(min_heap.begin(), min_heap.end(), std::greater<int>());
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (double)(max_heap[0] + min_heap[0]) / 2;
        } else if (max_heap.size() > min_heap.size()) {
            return (double)max_heap[0];
        } else {
            return (double)min_heap[0];
        }
    }

private:
    std::vector<int> max_heap;
    std::vector<int> min_heap;
};
