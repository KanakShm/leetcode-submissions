class Solution {
    public int characterReplacement(String s, int k) {
        /*
            length of the substring - most reoccurring letter <= k
            increase window size
            every time loop through hashmap<letter, count> and get the most frequent one
            check if length - most frequent > k
                yes: left++
            update res
        */

        int left = 0;
        int right = 0;
        int res = 0;
        Map<Character, Integer> count = new HashMap<>();
        while (right < s.length()) {
            count.put(s.charAt(right), count.getOrDefault(s.charAt(right), 0) + 1);

            while (left <= right && right - left + 1 - getHighestFreq(count) > k) {
                count.put(s.charAt(left), count.get(s.charAt(left)) - 1);
                left++;
            }

            res = Math.max(res, right - left + 1);
            right++;
        }
        
        return res;
    }

    public int getHighestFreq(Map<Character, Integer> count) {
        int highest_freq = 0;
        for (Map.Entry<Character, Integer> entry : count.entrySet()) {
            highest_freq = Math.max(highest_freq, entry.getValue());
        }
        return highest_freq;
    }
}
