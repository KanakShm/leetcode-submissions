class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            3 pointers
            left and right
            left pointer to the first element not = 0
            right pointer to the first element not = 2
            third pointer iterates through array
                if it sees 0 -> swaps with left
                if it sees 2 -> swaps with right
            only progress the pointer if we see a 1
                l r
            000010022222222
            l.    r
            1 0 1 2
        */

        int left = 0;
        int right = nums.size() - 1;
        
        while (left < nums.size() && nums[left] == 0) left++;
        while (right >= 0 && nums[right] == 2) right--;

        int i = left;
        while (left < right && i <= right) {
            if (nums[i] == 1) {
                i++;
                continue;
            }
            if (nums[i] == 0) {
                int temp = nums[left];
                nums[left] = nums[i];
                nums[i] = temp;
                i++;
                left++;
            } else {
                int temp = nums[right];
                nums[right] = nums[i];
                nums[i] = temp;
                right--;
            }
        }
    }
};