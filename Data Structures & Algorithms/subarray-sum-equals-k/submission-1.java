class Solution {
    public int subarraySum(int[] nums, int k) {
        /*
            prefix sum
            0 1
            2 2
            1 1
            4 1
            go through the hashmap and every time you have:
                curr sum + something in hashmap = k
                curr sum - k exists in hashmap
                res += the number of times that entity exists in the map
        */

        int res = 0;
        int sum = 0;
        Map<Integer, Integer> prefixSum = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            prefixSum.put(sum, prefixSum.getOrDefault(sum, 0) + 1);
            sum += nums[i];
            res += prefixSum.getOrDefault(sum - k, 0);
        }

        return res;
    }
}