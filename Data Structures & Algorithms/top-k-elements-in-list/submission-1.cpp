class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
            hashmap stores the numeber and freq
            iterate through hashmap and create new pair<frequency, number>
                max heap
            return k elements
            O(n) + O(log k)
        */

        std::unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }

        std::priority_queue<std::pair<int, int>> max_heap;
        for (auto iter = freq.begin(); iter != freq.end(); ++iter) {
            max_heap.push({iter->second, iter->first});
        }

        std::vector<int> res;
        while (k) {
            std::pair<int, int> top = max_heap.top();
            max_heap.pop();

            res.push_back(top.second);
            k--;   
        }

        return res;
    }
};
