class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*
            add current element to hashmap with its index <character, last index>
            once the list has been traversed traverse it again
                get the first element and see the farthest out we need to go
                iterate until that point or until we see another element that is farther
            
            after iterating through the first section iterate through the rest.
            O(n)
        */

        std::unordered_map<char, int> last_seen;
        for (int i = 0; i < s.size(); ++i) {
            last_seen[s[i]] = i;
        }

        int left = 0;
        int right = last_seen[0];
        int count = 0;
        std::vector<int> res;
        while (left < s.size()) {
            while (left <= right) {
                right = std::max(right, last_seen[s[left]]);
                count++;
                left++;
            }

            res.push_back(count);
            count = 0;
            right = last_seen[s[left]];
        }

        return res;
    }
};
