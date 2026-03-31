class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            size of substring - occurrance of top element = number of replacements
            number of replacements > k iterate left pointer should go to the first element not equal to top
            hashmap stores occurrance of all elements
            we store max value each instance

            l  r
            XYYX
            
        */
        std::unordered_map<char, int> umap;
        int left = 0;
        int right = 0;
        int global_max = INT_MIN;
        while (right < s.size()) {
            umap[s[right]]++;
            // get occurrance of the top element
            int max_occurrance = INT_MIN;
            for (auto iter = umap.begin(); iter != umap.end(); iter++) {
                max_occurrance = std::max(iter->second, max_occurrance);
            }
            while ((right - left + 1) - max_occurrance > k) {
                // shift left pointer forward
                umap[s[left]]--;
                if (umap.find(s[left]) == umap.end())
                    umap.erase(s[left]);
                left++;
            }
            right++;
            global_max = std::max(right - left, global_max);
        }
        return global_max;
    }
};