class Solution {
    public boolean hasDuplicate(int[] nums) {
        /*
            hashset<number>
            if we have seen the number in hashset, then return false
        */
        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) {
            if (seen.contains(nums[i])) return true;
            seen.add(nums[i]);
        }
        return false;
    }
}