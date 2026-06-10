class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
            loop through the nums and put everything in a hashmap
            loop through again to see if it couls be a starting value
                if that number - 1 doesnt exist in the map
            
            while the next element exists update to global max
            O(n) {
                O(n) (only when we find a starting number)

            }
        */

        std::unordered_set<int> elements;
        for (int i = 0; i < nums.size(); ++i) {
            elements.insert(nums[i]);
        }

        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!elements.count(nums[i] - 1)) {
                int curr_length = 0;
                int poll = nums[i];
                while (elements.count(poll)) {
                    curr_length++;
                    poll++;
                }

                res = std::max(res, curr_length);
            }
        }

        return res;
    }
};
