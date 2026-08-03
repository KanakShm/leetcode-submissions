class Solution {
    public int[] productExceptSelf(int[] nums) {
        /*
            two arrays:
                multiplies everything moving forward
                multiplies everything moving backward
            
            iterate through the array and multiply i - 1 with i + 1
            only if i - 1 and i + 1 exist

            2 2 3 4
            48 24 12 4 1
            1 2 4 12 48
        */

        int[] forwardMult = new int[nums.length + 1];
        forwardMult[0] = 1;

        int[] backwardMult = new int[nums.length + 1];
        backwardMult[nums.length] = 1;

        for (int i = 1; i <= nums.length; ++i) {
            forwardMult[i] = forwardMult[i - 1] * nums[i - 1];
            backwardMult[nums.length - i] = backwardMult[nums.length - i + 1] * nums[nums.length - i];
        }

        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            res[i] = forwardMult[i] * backwardMult[i + 1];
        }

        return res;
    }
}  
