class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
            hashmap to store number and frequency
            push all numbers that appear more than n/2 times to res
        */
        std::unordered_map<int, int> count;
        int k = nums.size() / 3 + 1;
        std::vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
            if (count[nums[i]] == k) res.push_back(nums[i]);
        }

        return res;
    }
};