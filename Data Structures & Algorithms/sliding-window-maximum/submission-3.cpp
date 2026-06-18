class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
            left and right pointer k steps away
                put everything in a max heap
                once the right pointer is k steps away then add heap top
            increment right pointer add to heap
            increment left pointer -> need to remove element

            hashmap<number, count>
            when you increment the left pointer you decrement the count
            when you want to find the max then you pop off the heap
            while the top count == 0
            n*log(k)
        */
        std::unordered_map<int, int> count;
        std::priority_queue<std::pair<int, int>> max_heap;

        int left = 0;
        int right = 0;

        while (right < nums.size() && right - left < k) {
            count[nums[right]]++;
            max_heap.push({nums[right], count[nums[right]]});
            right++;
        }

        std::vector<int> res;
        while (right <= nums.size()) {
            res.push_back(max_heap.top().first);

            if (right >= nums.size()) break;
            count[nums[right]]++;
            max_heap.push({nums[right], count[nums[right]]});

            count[nums[left]]--;
            left++; 
            right++;

            while (count[max_heap.top().first] == 0) {
                max_heap.pop();
            }          
        }

        return res;
    }
};
