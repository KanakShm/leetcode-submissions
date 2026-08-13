class Solution {
    public String minWindow(String s, String t) {
        /*
            create hashmap with string t
            increase window size in s until frequency matches t
                update shortes string as left and right pointers
            
            reduce window size until first letter removed where frequency
            dips below required

            then increase right side
        */
        if (t.length() > s.length()) return "";

        Map<Character, Integer> needed = new HashMap<>();
        for (int i = 0; i < t.length(); ++i) {
            needed.put(t.charAt(i), needed.getOrDefault(t.charAt(i), 0) + 1);
        }

        int left = 0;
        int right = 0;
        int left_res = -9999999;
        int right_res = 9999999;
        Map<Character, Integer> contains = new HashMap<>();
        while (left < s.length()) {
            while (right < s.length() && !validSubstr(contains, needed)) {
                contains.put(s.charAt(right), contains.getOrDefault(s.charAt(right), 0) + 1);
                right++;
            }

            if (validSubstr(contains, needed) && right - left + 1 < right_res - left_res + 1) {
                right_res = right;
                left_res = left;
            }

            
            contains.put(s.charAt(left), contains.get(s.charAt(left)) - 1);
            if (contains.get(s.charAt(left)) == 0) contains.remove(s.charAt(left));
            left++;
        }

        if (right_res == 9999999) return "";
        return s.substring(left_res, right_res);
    }

    public boolean validSubstr(Map<Character, Integer> contains, Map<Character, Integer> needed) {
        for (Map.Entry<Character, Integer> entry : needed.entrySet()) {
            if (!contains.containsKey(entry.getKey()) || 
                entry.getValue() > contains.get(entry.getKey())) return false;
        }

        return true;
    }
}
