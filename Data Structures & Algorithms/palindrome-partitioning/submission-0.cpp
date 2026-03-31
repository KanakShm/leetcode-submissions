class Solution {
public:
    bool isPalendrome(std::string& str) {
        if (str.empty()) return false;
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    vector<vector<string>> partition(string s) {
        /*
            backtracking algorithm where we dfs through the string
            partition the string and verify that it is a palendrome
            if it is then we add it to the local group
            local group only gets pushed to the result array if i == s.size and concatenation of
            local group is equal to s
            need a way to first choose one elemnent at a time, then move to two elements and so on
            use a for loop to partition the string on each callback of the backtrack
        */
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> local_group;
        backtrack(0, res, local_group, s);
        return res;
    }

    void backtrack(int i, std::vector<std::vector<std::string>>& res, std::vector<std::string>& local_group, std::string s) {
        if (i == s.size()) {
            std::string str = "";
            for (int i = 0; i < local_group.size(); ++i) {
                str += local_group[i];
            }

            if (str == s) {
                res.push_back(local_group);
            }
        }

        // For loop that partitions the strings and updates local group
        // local group only updates if it is a palendrome otherwise we skip the partition
        for (int j = i; j < s.size(); ++j) {
            std::string part = s.substr(i, j - i + 1);
            if (isPalendrome(part)) {
                local_group.push_back(part);
                backtrack(j + 1, res, local_group, s);
                local_group.pop_back();
            }
        }
    }

};
