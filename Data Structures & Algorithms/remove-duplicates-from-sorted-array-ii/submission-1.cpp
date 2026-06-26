class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
            input array sorted
            two pointers
            if curr element = prev then decrement count until 0
            while count = 0 and curr element = prev element increment right pointer
            updatel left pointer to equal right pointer
            repeat
            
                r
            11222234556777

            while n > 2 and we have the same value
                increment left and right
            while n == 0 and we are at the same prev value then increment right
            update the prev value ot right and reset n to 2
            update left to be right and increment left and decrement n > 0
        */

        int left = 0;
        int right = 0;
        int prev = nums[0];
        int n = 2;
        while (right < nums.size()) {
            while (right < nums.size() && nums[right] == prev && n > 0) {
                left++;
                right++;
                n--;
            }

            if (right < nums.size() && nums[right] != prev) {
                n = 2;
                prev = nums[right];
            }

            while (n == 0 && right < nums.size() && nums[right] == prev) {
                right++;
            }

            n = 2;
            while (n > 0 && left < right && right < nums.size()) {
                if (right < nums.size() && nums[right] != prev) {
                    n = 2;
                    prev = nums[right];
                }
                nums[left] = nums[right];
                left++;
                right++;
                n--;
            }
        }

        return left;
    }
};