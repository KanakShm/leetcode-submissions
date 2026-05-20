class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /*
            keep track of two pointers pos and neg
            maintain an array
            pos and neg should find the first pos and neg values
            pushback to array the positve then the negative
        */

        int pos = 0;
        int neg = 0;
        std::vector<int> res;
        while (pos < nums.size() || neg < nums.size()) {
            while (pos < nums.size() && nums[pos] < 0) pos++;
            while (neg < nums.size() && nums[neg] > 0) neg++;

            if (pos < nums.size())
                res.push_back(nums[pos]);

            if (neg < nums.size())
                res.push_back(nums[neg]);
            pos++;
            neg++;
        }

        if (pos < nums.size())
            res.push_back(nums[pos]);
        
        if (neg < nums.size())
            res.push_back(nums[neg]);

        return res;
    }
};