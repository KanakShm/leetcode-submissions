class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            hashmap<int, vector> sum of (i and j) * -1, vector = i , j;
            iterate k forward if k exists in the hashmap then we have i,j,k return 
            4 -> [[0,1],[2,3]]

            Sort the nums array
            loop through the array and add to hashmap<number, count>

            double for loop and see if i and j * -1 exists in the hashmap
            if it does then add i, j and target to a container and push to output array

            to make sure there are no duplicates, always start j = i + 1;
            and also if the current element is the same as the previous one skip it

            -2, -1, 3
            -4, -1, -1, 0, 1, 2
            -4: 1
            -1: 2
             0: 1
             2: 1
        */

        // Generate the hashmap from the ordered nums array
        std::sort(nums.begin(), nums.end(), std::less<int>());
        std::unordered_map<int,int> umap;
        std::for_each(nums.begin(), nums.end(), [&](int num) {
            umap[num]++;
        });

        // Two pointers approach
        std::vector<std::vector<int>> output;
        for (int i = 0; i < nums.size() - 1; ++i) {
            umap[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int target = -1 * (nums[i] + nums[j]);
                if (target < nums[j]) continue;
                umap[nums[j]]--;
                if (umap.find(target) != umap.end() && umap[target] > 0) {
                    std::vector<int> container;
                    std::cout << i << " " << j << " " << umap[nums[j]] << std::endl;
                    container.push_back(nums[i]);
                    container.push_back(nums[j]);
                    container.push_back(target);
                    output.push_back(container);
                }
                umap[nums[j]]++;
            }
        }
        return output;
    }
};
