class Solution {
    public int[] twoSum(int[] numbers, int target) {
        /*
            left pointer at the start
            right pointer at the end

            if left + right > target -> right--
            if left + right < target -> left++
            if left + right = target return {left, right}
        */

        int left = 0;
        int right = numbers.length - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                return new int[] {left + 1, right + 1};
            }
        }

        return new int[0];
    }
}
