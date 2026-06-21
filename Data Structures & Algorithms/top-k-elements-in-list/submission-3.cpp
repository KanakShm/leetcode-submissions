class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
            count freq of each number
            freq vector of vectors that contains numbers with specific frequency
            in given index
            return last k elements
        */

        std::unordered_map<int, int> count;
        std::vector<std::vector<int>> freq(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }

        for (auto iter = count.begin(); iter != count.end(); ++iter) {
            freq[iter->second].push_back(iter->first);
        }

        std::vector<int> res;
        for (int i = freq.size() - 1; i >= 0; --i) {
            for (int j = 0; j < freq[i].size(); ++j) {
                res.push_back(freq[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};
