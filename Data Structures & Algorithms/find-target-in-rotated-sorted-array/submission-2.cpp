class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
            Middle is greater than right
                target is between middle and right if yes shift down if no shift up
            Middle is smaller than right
                target is between middle and right if yes shift up if no shift down

            l.   h
            [3,4,5,6,1,2]
            [3,5,6,0,1,2]
            [1,2,3,4,5,6]
        */

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (nums[middle] == target) return middle;

            if (nums[middle] > nums[high]) {
                if (target < nums[middle] && target > nums[high]) {
                    high = middle - 1;
                } else {
                    low = middle + 1;
                }
            } else {
                if (target > nums[middle] && target <= nums[high]) {
                    low = middle + 1;
                } else {
                    high = middle - 1;
                }
            }
        }

        return -1;
    }
};
