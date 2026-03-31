class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        left and right pointer starting at 0 and 1
        if right = left move left forward
        if right != left move right forward
        if right pointer = left pointer then move right forward
        keep track of max index difference
        
        longest:3
            l  r
        zxyzxyz

           lr
        xxxx

        max:3
        
        lr
        abcabcbb

           l r
        abcsisuyts
        */
        if (s.empty()) {
            return s.size();
        }

        int longest_substring = 1;
        int left = 0;
        int right = left + 1;
        std::unordered_map<char, int> umap;
        umap[s[left]]++;
        while (right <= s.size()) {
            std::cout << left << " " << right << std::endl;
            longest_substring = std::max(longest_substring, right - left);
            if (umap.find(s[right]) == umap.end()) {
                umap[s[right]]++;
                right++;
            } else {
                umap[s[left]]--;
                if (umap[s[left]] <= 0) umap.erase(s[left]);
                left++;
            }
        }

        return longest_substring;
    }
};
