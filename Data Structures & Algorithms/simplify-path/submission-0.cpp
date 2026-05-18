class Solution {
public:
    string simplifyPath(string path) {
        /*
            Vector of folders
            loop through string if we see .. then pop
            separate words by /
        */

        std::vector<std::string> folders;
        int i = 0;
        while (i < path.size()) {
            std::string folder = "";
            if (path[i] == '/') {
                i++;
                continue;
            }

            while (i < path.size() && path[i] != '/') {
                folder.push_back(path[i]);
                i++;
            }

            if (folder == ".." && !folders.empty()) {
                folders.pop_back();
            } else if (!folder.empty() && folder != "." && folder != "..") {
                folders.push_back(folder);
            }

            i++;
        }

        if (folders.empty()) return "/";

        std::string res;
        for (int j = 0; j < folders.size(); ++j) {
            res += '/';
            res += folders[j];
        }

        return res;
    }
};