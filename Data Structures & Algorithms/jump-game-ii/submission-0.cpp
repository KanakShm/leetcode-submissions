class Solution {
public:
    int jump(vector<int>& nums) {
        /*
            initialise a left and right pointer
            always jump right to the farthest point
            always iterarate left poitner and update the next farthest point to traverse

            [4,1,1,1,0,2,1]
        */

        int l = 0;
        int r = 0;
        int res = 0;

        while (r < nums.size() - 1) {
            int farthest = 0;
            while (l <= r) {
                farthest = std::max(farthest, nums[l]);
                l++;
            }

            r += farthest;
            res++;
        }

        return res;
    }
};
