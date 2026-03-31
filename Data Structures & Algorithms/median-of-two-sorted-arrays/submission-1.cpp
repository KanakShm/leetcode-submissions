class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        [12345, 2]
        [1569, 123]. 1123569
        */
        int total = (nums1.size() + nums2.size());
        int half = (total)/ 2;

        std::vector<int> A = nums1;
        std::vector<int> B = nums2;

        if (nums1.size() > nums2.size()) {
            A = nums2;
            B = nums1;
        }

        /*
        half = 1
        i = 0
        j = -1
        a_left = 3
        a_right = INT_MAX
        b_left = INT_MIN
        b_right = 1
        */
        int high = A.size();
        int low = 0;
        while (low <= high) {
            int i = (high + low) / 2;   // How many elements from A
            int j = half - i;   // How many elements from B

            int a_left = i > 0 ? A[i-1] : INT_MIN;
            int a_right = i < A.size() ? A[i] : INT_MAX;
            int b_left = j > 0 ? B[j-1] : INT_MIN;
            int b_right = j < B.size() ? B[j] : INT_MAX;

            if (a_left <= b_right && b_left <= a_right) {
                if (total % 2 == 0) {
                    int sum = std::max(a_left, b_left) + std::min(a_right, b_right);
                    return sum / 2.0;
                } else {
                    return std::min(a_right, b_right);
                }
            } else if (a_left > b_right) {
                // We need less from array A
                high = i - 1;
            } else {
                // We need more from array A
                low = i + 1;
            }
        }
        return -1.0;
    }
};
