class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            Sliding window:
            increase window size if the size of string - most frequent element is <= k
            if it is more than k then move window forward
            to get count of most frequent letter:
                hashmap and loop through this every time O(26)
            
                r
            l
            AAABABB
        */
        int res = 0;
        std::unordered_map<char, int> umap;

        int left = 0;
        int right = 0;

        umap[s[left]]++;
        while (left < s.size()) {
            int size = right - left + 1;
            // Find the most frequent element count
            int most_freq = 0;
            for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
                most_freq = std::max(most_freq, iter->second);
            }

            if (size - most_freq <= k && right < s.size()) {
                res = std::max(res, size);
                right++;
                umap[s[right]]++;
            } else {
                umap[s[left]]--;
                if (umap.find(s[left]) == umap.end()) {
                    umap.erase(s[left]);
                }
                left++;
            }
        }
        return res;
    }
};