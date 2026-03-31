class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            umap[nums[i]]++;
        }

        std::vector<int> res;
        int count = nums.size() / 3;
        for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
            if (iter->second > count) {
                res.push_back(iter->first);
            }
        }
        
        return res;
    }
};