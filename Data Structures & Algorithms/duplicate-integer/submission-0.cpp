class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool duplicate = false;
        std::for_each(nums.begin(), nums.end(), [&](int num) {
            if (umap.find(num) != umap.end()) {
                duplicate = true;
            } else {
                umap[num]++;
            }
        });

        return duplicate;
    }

private:
    std::unordered_map<int, int> umap;
};