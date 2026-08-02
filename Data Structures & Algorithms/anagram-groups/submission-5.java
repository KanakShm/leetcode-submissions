class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        /*
            hashmap of strings of 26 characters denoting the count of each letter
            iterate through the strs list and create a new string that maps to the current
            strs element

            iterate through the hashmap and group into a return list of list
        */

        Map<String, List<String>> anagrams = new HashMap<>();
        for (int i = 0; i < strs.length; ++i) {
            int[] count = new int[26];
            for (int j = 0; j < strs[i].length(); ++j) {
                count[strs[i].charAt(j) - 'a']++;
            }

            String key = "";
            for (int j = 0; j < count.length; ++j) {
                key += count[j] + "#";
            }

            anagrams.putIfAbsent(key, new ArrayList<String>());
            anagrams.get(key).add(strs[i]);
        }

        List<List<String>> res = new ArrayList<>();
        for (Map.Entry<String, List<String>> entry : anagrams.entrySet()) {
            res.add(entry.getValue());
        }

        return res;
    }
}
