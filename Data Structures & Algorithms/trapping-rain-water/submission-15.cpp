class Solution {
public:
    int trap(vector<int>& height) {
       /*
            start two pointers at the start
            increment right until we find a height larger than = left
            each time we increment we add to total water
            when we find heght larger, set left pointer to that and repeat

            iterate right to the first element larger than left
            each time we iterate we calculate how much more water we can add

            height=[0,1,0,2,1,0,1,3,2,1,2,1]

       */

        int left = 0;
        int right = 1;
        int total = 0;
        int max_index = INT_MAX;
        while (left < height.size()) {
            int water = 0;
            while (right < height.size() && height[right] < height[left]) {
                water += height[left] - height[right];
                right++;
            }

            if (right == height.size()) {
                water = 0;
                max_index = left;
            }

            total += water;
            left = right;
            right++;
        }

        right = height.size() - 1;
        left = height.size() - 2;
        while (right > max_index) {
            int water = 0;
            while (left >= 0 && height[left] < height[right]) {
                water += height[right] - height[left];
                left--;
            }

            total += water;
            right = left;
            left--;
        }

        return total;
    }
};
