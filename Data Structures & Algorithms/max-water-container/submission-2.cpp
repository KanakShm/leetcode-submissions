class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
            start two pointers to the left and right
            calculate the max as min(left, right) * distance
            increment the smaller one forward
                we can potentially get a larger value
        */

        int left = 0;
        int right = heights.size() - 1;

        int res = 0;
        while (left < right) {
            int area = std::min(heights[right], heights[left]) * (right - left);
            res = std::max(res, area);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};
