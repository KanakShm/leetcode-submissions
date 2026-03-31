class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
            convert nums to hashmap
            iterate hashmap if nums[i] - 1 exists in the hashmap then continue
            if it doesnt then start at nums[i] and while the next number exists increment max count
        
            [0,3,2,5,4,6,1,1]
            [2,20,4,10,3,4,5]
        */
        

        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(nums[i]) == umap.end()) {
                umap[nums[i]]++;
            }
        }

        int max_count = 0;
        int increment = 1;
        for (auto i = umap.begin(); i != umap.end(); ++i) {
            // potential starting point of a sequence
            if (umap.find(i->first - 1) == umap.end()) {
                int curr_max = 1;
                while (umap.find(i->first + increment) != umap.end()) {
                    curr_max++;
                    increment++;
                }
                max_count = std::max(curr_max, max_count);
                increment = 1;
            }
        }
        return max_count;
    }
};
