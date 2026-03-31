class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            pass through everything except for the first nums 
            int permute func

            base case if nums.size() == 0 then return an empty list
            once we get an empty list (or a returned result list) we go through it and
            add the first nums to each of the places.
            return the result list
        */
        return backtrack(nums);
    }
    
    std::vector<std::vector<int>> backtrack(std::vector<int>& nums) 
    {
        if (nums.size() == 0) {
            return {{}};
        }

        std::vector<int> segmented_nums = std::vector<int>(nums.begin() + 1, nums.end());
        std::vector<std::vector<int>> res = backtrack(segmented_nums);

        // Now we have the final element (empty list) we need to append the current 
        // number in all locations

        /*
            {{3}}
            {{2,3},{3,2}}
            
        */
        std::vector<std::vector<int>> new_res;
        for (int i = 0; i < res.size(); ++i) {
            for (int j = 0; j <= res[i].size(); ++j) {
                std::vector<int> copy = res[i];
                copy.insert(copy.begin() + j, nums[0]);
                new_res.push_back(copy);
            }
        }
        return new_res;
    }
};
