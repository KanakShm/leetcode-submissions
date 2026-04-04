class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
            sorted array -> we can traverse to the closest element to x
            start left and right pointers from that position
            left moves down while right moves up
            if left is closer you add to result array you move it down and vice versa for right

            [2,4,5,8]  k = 2, x = 6
        */

        std::vector<int> res;
        int idx = 0;
        int closest = std::abs(arr[0] - x);
        for (int i = 0; i < arr.size(); ++i) {
            int diff = std::abs(arr[i] - x);
            if (closest > diff) {
                closest = diff;
                idx = i;
            }
        }
        
        int left = idx;
        int right = idx;
        
        while ((left >= 0 || right < arr.size()) && (right - left + 1) < k) {
            int diff_left = INT_MAX;
            int diff_right = INT_MAX;

            if (left  - 1 >= 0) {
                diff_left = std::abs(arr[left - 1] - x);
            }

            if (right + 1 < arr.size()) {
                diff_right = std::abs(arr[right + 1] - x);
            }

            if (diff_left <= diff_right) {
                left--;
            } else {
                right++;
            }
        }
        
        left = std::max(0, left);
        right = std::min((int)arr.size() - 1, right);
        for (int i = left; i <= right; ++i) {
            res.push_back(arr[i]);
        }

        return res;
    }
};