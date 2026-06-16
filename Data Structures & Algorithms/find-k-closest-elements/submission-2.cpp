class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
            loop till we find the first element that is = x or closest to x
            get right and left pointer, increment right pointer if it is closer otherwise increment left pointer
            add elements to the result
            loop k times
        */

        int start = 0;
        while (start < arr.size() && arr[start] <= x) {
            start++;
        }

        if (start - 1 >= 0 && std::abs(arr[start] - x) > std::abs(arr[start - 1] - x)) {
            start--;
        }

        std::vector<int> res;
        res.push_back(arr[start]);
        k--;

        int left = start - 1;
        int right = start + 1;

        while (k) {
            if (left < 0 && right < arr.size()) {
                res.push_back(arr[right]);
                right++;
            } else if (left >= 0 && right >= arr.size()) {
                res.push_back(arr[left]);
                left--;
            } else if (std::abs(arr[right] - x) < std::abs(arr[left] - x)) {
                res.push_back(arr[right]);
                right++;
            } else if (std::abs(arr[right] - x) >= std::abs(arr[left] - x)) {
                res.push_back(arr[left]);
                left--;
            }
            k--;
        }

        std::sort(res.begin(), res.end());
        return res;
    }
};