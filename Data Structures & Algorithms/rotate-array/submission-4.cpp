class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*  
            create a new array res
            new index = (i + k) % nums.size()
        */
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());

        // reverese the first k elements
        int left = 0;
        int right = k - 1;
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }

        // Reverse the rest
        left = k;
        right = nums.size() - 1;
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
};