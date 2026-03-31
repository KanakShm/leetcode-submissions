class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            hashmap that stores the count of each number O(3)
            go through and update the array
        */

        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            umap[nums[i]]++;
        }

        int idx = 0;
        for (int i = 0; i < 3; ++i) {
            int count = umap[i];
            while (count > 0) {
                nums[idx] = i;
                idx++;
                count--;
            }
        }
    }
};