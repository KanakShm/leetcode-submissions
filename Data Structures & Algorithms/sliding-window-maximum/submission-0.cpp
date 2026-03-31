#include <bits/stdc++.h>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
            [1,4,100,99,50]
            iterate through the array
            for each number in right you add to the heap
            after k elements added you pop from max heap
            keep popping until the index falls within our left and right range
        */

        std::vector<std::pair<int,int>> heap;
        std::vector<int> output;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            while (right - left < k) {
                heap.push_back(std::make_pair(nums[right], right));
                std::push_heap(heap.begin(), heap.end(), std::less<std::pair<int, int>>());
                right++;
            }
            std::pair<int, int> top = heap[0];
            while (top.second < left || top.second > right) {
                std::pop_heap(heap.begin(), heap.end(), std::less<std::pair<int, int>>());
                heap.pop_back();
                top = heap[0];
            }
            output.push_back(top.first);
            left++;
        }
        return output;
    }
};
