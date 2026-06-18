class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
            they are the same number
            the distance between them is k

            keep a sliding window of size k
            iterate both left and right pointer forward until they match
            return true if they do false if we end the array

            hashmap to record what is currently in the sliding window
            99 99
        */

        if (k == 0) return false;

        int left = 0;
        int right = 0;

        std::unordered_map<int, int> count;
        while (right < nums.size() && right - left <= k) {
            if (count.find(nums[right]) != count.end()) return true;
            count[nums[right]]++;
            right++;
        }

        while (right < nums.size()) {
            count[nums[left]]--;
            if (count[nums[left]] <= 0) count.erase(nums[left]);

            if (count.find(nums[right]) != count.end()) return true;

            count[nums[right]]++;
            left++;
            right++;
        }

        return false;
    }
};