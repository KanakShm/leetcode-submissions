class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
                 r                l
            1, 1, 1000000, 2, 10, 1
            
            l   r
            2,2,2

            Initialise 2 pointers at the start
            move the smaller pointer forward to the next index
            if both are same, move the rightmost pointer

            [2,1,1,1,4,6,10]
            1,2
            1.  1
            2   1
        */

        int max_area = 0;
        int l = 0;
        int r = heights.size() - 1;
        while (l < r) {
            int curr_area = std::min(heights[l], heights[r]) * (r - l);
            max_area = std::max(curr_area, max_area);
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] >= heights[r]) {
                r--;
            }
        }
        return max_area;
    }
};
