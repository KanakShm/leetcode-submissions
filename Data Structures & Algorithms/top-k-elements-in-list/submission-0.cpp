#include <array>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Hashmap of key = number, value = count
        // Populate an vector [count, number]
        // feed into a heap
        // pop k times

        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            umap[nums[i]]++;
        }

        std::vector<std::array<int, 2>> heap;
        for (auto i = umap.begin(); i != umap.end(); ++i) {
            std::array<int, 2> arr = {i->second, i->first};
            heap.push_back(arr);
        }

        std::make_heap(heap.begin(), heap.end(), std::less<std::array<int, 2>>());
        std::vector<int> output;

        while (k > 0) {
            output.push_back(heap[0][1]);
            std::pop_heap(heap.begin(), heap.end(), std::less<std::array<int, 2>>());
            heap.pop_back();
            k--;
        }
        
        return output;
    }
};
