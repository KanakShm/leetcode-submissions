class Solution {
public:
    int trap(vector<int>& height) {
        /*
            area enclosed is from current block to the next one equal to it or greater than
            for each index starting from current block area += curr_height - height[i] up until 
            height[i] >= curr_height
        */

        int max_area_forward = 0;
        int l = 0;
        int r = 0;
        while (r < height.size() && l < height.size()) {
            // find first instance of r greater than equal to height[l]
            r++;
            while (height[r] < height[l] && r < height.size()) {
                r++;
            }

            if (r >= height.size()) break;

            // calculate area between l and r
            int curr_area = 0;
            int curr_bar_height = height[l];
            l++;
            while (l < r) {
                // std::cout << l << " " << r << std::endl;
                curr_area += curr_bar_height - height[l];
                l++;
            }

            max_area_forward += curr_area;
        }

        r = height.size() - 1;
        l = height.size() - 1;
        int max_area_backward = 0;

        while (l >= 0 && r >= 0) {
            // iterate l until something bigger than or equal to
            l--;
            while (height[l] <= height[r]) {
                l--;
            }

            if (l < 0) break;

            // update area from right pointer to left
            int curr_area = 0;
            int lowest_bar = height[r];
            r--;
            while (r > l) {
                curr_area += lowest_bar - height[r];
                r--;
            }
            max_area_backward += curr_area;
        }

        return max_area_forward + max_area_backward;
    }

};
