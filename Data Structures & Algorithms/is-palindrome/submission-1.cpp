class Solution {
public:
    bool isPalindrome(string s) {
        /*
            Have two pointers starting from the left and the right
            if they equal each other then iterate left by one and decrement right by 1 
            do this until l <= r
            l  r
            [baab]
            [kanak]
            if they dont equal return false
        */

        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if ((std::tolower(s[l]) < 'a' || 
                std::tolower(s[l]) > 'z') &&
                (std::tolower(s[l]) < '0' ||
                std::tolower(s[l]) > '9')) {
                l++;
                continue;
            }
            if ((std::tolower(s[r]) < 'a' || 
                std::tolower(s[r]) > 'z') &&
                (std::tolower(s[r]) < '0' ||
                std::tolower(s[r]) > '9')) {
                r--;
                continue;
            }

            if (std::tolower(s[l]) != std::tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
