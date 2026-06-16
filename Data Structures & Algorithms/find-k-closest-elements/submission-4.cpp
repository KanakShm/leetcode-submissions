class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;

        std::vector<int> res;
        while (right - left + 1 > k) {
            if (std::abs(arr[right] - x) >= std::abs(arr[left] - x)) {
                right--;
            } else {
                left++;
            }
        }

        while (left <= right) {
            res.push_back(arr[left]);
            left++;
        }
        
        return res;
    }
};