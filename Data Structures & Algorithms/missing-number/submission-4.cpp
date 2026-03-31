class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            hashmap stores all numbers
            iterate through hashmap with i = 0 to i = n
            if i doesnt exist return i
        */
        std::unordered_set<int> uset;
        for (int i = 0; i < nums.size(); ++i) {
            uset.insert(nums[i]);
        }

        int i = 0;
        for (auto iter = uset.begin(); iter != uset.end(); ++iter) {
            if (uset.find(i) == uset.end()) {
                return i;
            }
            i++;
        }
        return i;
    }
};
