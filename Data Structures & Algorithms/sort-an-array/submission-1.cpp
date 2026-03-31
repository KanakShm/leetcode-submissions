class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        /*
            Recursively split the array into left and right

            Base case:
                if the array is empty return
            
        */
        if (nums.size() == 1) return nums;

        std::vector<int> left;
        std::vector<int> right;
        for (int i = 0; i < nums.size() / 2; ++i) {
            left.push_back(nums[i]);
        }

        for (int i = nums.size() / 2; i < nums.size(); ++i) {
            right.push_back(nums[i]);
        }

        std::vector<int> r_left = sortArray(left);
        std::vector<int> r_right = sortArray(right);

        std::vector<int> res;

        int l = 0;
        int r = 0;
        while (l < r_left.size() && r < r_right.size()) {
            if (r_left[l] < r_right[r]) {
                res.push_back(r_left[l]);
                l++;
            } else {
                res.push_back(r_right[r]);
                r++;
            }
        }

        while (l < r_left.size()) {
            res.push_back(r_left[l]);
            l++;
        }

        while (r < r_right.size()) {
            res.push_back(r_right[r]);
            r++;
        }

        return res;
    }
};