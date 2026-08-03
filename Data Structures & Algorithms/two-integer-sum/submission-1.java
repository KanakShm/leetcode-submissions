class Solution {
    public int[] twoSum(int[] nums, int target) {
        /*
            create hashmap and if we ever find target - current number in it then
            return that index and current index

            hashmap<nums[i], i>
            if element already exists while iterating, dont update the value in the hashmap
        */

        Map<Integer, Integer> firstOccurrance = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (firstOccurrance.containsKey(target - nums[i])) {
                return new int[] { firstOccurrance.get(target - nums[i]), i };
            }

            firstOccurrance.putIfAbsent(nums[i], i);
        }

        return new int[] {};
    }
}
