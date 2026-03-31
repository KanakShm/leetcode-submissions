class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            Create a hashmap of s1
            have two pointers l and r pointing to 0
            increment both pointers if r is not in hashmap
            increment only right if r is in hashmap
                decrement hashmap count of element
                if hashmap's is empty remove the element
                if hashmap is empty return true
            if we see that the r is not in hashmap then reset hashmap to previous
            and left = right pointer'

            abc
              l   r                
            hgababc
        */
        std::unordered_map<char, int> umap;
        for (int i = 0; i < s1.size(); ++i) {
            umap[s1[i]]++;
        }

        std::unordered_map<char, int> umap_copy = umap;
        int left = 0;
        int right = 0;
        while (right < s2.size()) {
            std::cout << left << " " << right << std::endl;
            if (umap_copy.find(s2[right]) == umap_copy.end()) {
                umap_copy = umap;
                left++;
                right = left;
            } else {
                umap_copy[s2[right]]--;
                if (umap_copy[s2[right]] <= 0) {
                    umap_copy.erase(s2[right]);
                }

                if (umap_copy.empty()) {
                    return true;
                }
                right++;
            }
        }
        return false;
    }
};
