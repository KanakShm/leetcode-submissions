class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
            i + j = target
            target - i = j;
        */
        std::vector<int> output;
        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(nums[i]) != umap.end()) {
                std::cout << nums[i] << std::endl;    
                output.push_back(umap[nums[i]]);
                output.push_back(i);
                break;
            } else {
                umap.insert({target - nums[i], i});
            }
        }
        return output;
    }

private:
    std::unordered_map<int, int> umap;
};
