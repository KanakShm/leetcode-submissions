class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
           Keep a deque of integers
           Add to the back of the deque if it is smaller than the top element
        */

        std::deque<int> scope;
        std::vector<int> output;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            while (!scope.empty() && nums[scope.back()] < nums[right]) {
                scope.pop_back();
            }
            scope.push_back(right);
            if (left > scope.front()) {
                scope.pop_front();
            }

            if (right + 1 >= k) {
                output.push_back(nums[scope.front()]);
                left++;
            }
            right++;
        }

        return output;
    }
};
