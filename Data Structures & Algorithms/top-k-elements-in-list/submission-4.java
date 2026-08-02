class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        /*
            sort the array then iterate to fill k distinct numbers
            nlogn

            hashmap with count of each element
            initialise min heap with size k
            nlogk
        */

        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i) {
            count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
        }

        /* In a lambda expression, if:
            the result < 0, the first element goes first
            the result > 0, the second element goes first
            the result = 0, both are equal

            1 2 3
        */

        PriorityQueue<int[]> min_heap = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            min_heap.offer(new int[]{entry.getValue(), entry.getKey()});
            if (min_heap.size() > k) min_heap.poll();
        }

        int[] res = new int[k];
        while (!min_heap.isEmpty()) {
            res[--k] = min_heap.poll()[1];
        }

        return res;
    }
}
