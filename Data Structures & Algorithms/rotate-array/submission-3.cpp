class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*  
            create a new array res
            new index = (i + k) % nums.size()
        */

        std::vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            int idx = (i + k) % nums.size();
            res[idx] = nums[i];
        }

        nums = res;
    }
};