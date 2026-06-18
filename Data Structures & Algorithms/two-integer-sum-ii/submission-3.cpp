class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
            iterate through the list and record numbers in a hashmap
            each time we get to a new number we ask if we have seen
                target - number -> return those indices if we have
            
            always increasing / the same
            start pointers on either ends
            if the sum is < than target increment left pointer
            else decrement right pointer

            1 3 3 3 4 5 5 6
            8
        */

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] == target) return {left + 1, right + 1};
            if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                right--;
            }
        }

        return {0,0};
    }
};
