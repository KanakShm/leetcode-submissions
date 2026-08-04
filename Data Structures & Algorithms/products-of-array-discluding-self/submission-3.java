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

            1 2 4 6
            
            1 1 2 8 48
            1 6 24 48 48
        */

        ArrayList<Integer> forwardMult = new ArrayList<>();
        ArrayList<Integer> backwardMult = new ArrayList<>();

        int forward = 1;
        int backward = 1;

        for (int i = 0; i < nums.length; ++i) {
            forwardMult.add(forward);
            backwardMult.add(backward);
            forward *= nums[i];
            backward *= nums[nums.length - 1 - i];
        }

        forwardMult.add(forward);
        backwardMult.add(backward);

        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            res[i] = forwardMult.get(i) * backwardMult.get(backwardMult.size() - 2 - i);
        }

        return res;
    }
}  
