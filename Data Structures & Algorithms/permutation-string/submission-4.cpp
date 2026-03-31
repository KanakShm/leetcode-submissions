class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
            Build hashmap of s1
            sliding window of where r iterates s1.size() accross first and 
            builds its own hashtable 
            iterate thorught the hash table and check if they are all equal return true if yes
            if no then slide accross and update s2 hashtable
        */

        std::vector<int> arr1(26, 0);
        std::vector<int> arr2(26, 0);
        // Populate both arrays with current 'window'
        for (int i = 0; i < s1.size(); ++i) {
            arr1[s1[i] - static_cast<int>('a')]++;
            arr2[s2[i] - static_cast<int>('a')]++;
        }

        int matches = 0;
        for (int i = 0; i < arr1.size(); ++i) {
            if (arr1[i] == arr2[i]) matches++;
        }
        
        int right = s1.size();
        int left = 0;
        while (right < s2.size()) {
            if (matches == 26) return true;
            // add the right element
            arr2[s2[right] - static_cast<int>('a')]++;
            if (arr1[s2[right] - static_cast<int>('a')] ==
                arr2[s2[right] - static_cast<int>('a')]) {
                    matches++;
            } else if (arr1[s2[right] - static_cast<int>('a')] ==
                       arr2[s2[right] - static_cast<int>('a')] - 1) {
                    matches--;
            }


            // remove the left element
            arr2[s2[left] - static_cast<int>('a')]--;
            if (arr1[s2[left] - static_cast<int>('a')] ==
                arr2[s2[left] - static_cast<int>('a')]) {
                    matches++;
            } else if (arr1[s2[left] - static_cast<int>('a')] ==
                       arr2[s2[left] - static_cast<int>('a')] + 1) {
                    matches--;
            }

            right++;
            left++;
        }

        return matches == 26;
    }
};
