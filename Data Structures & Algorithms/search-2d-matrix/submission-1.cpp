class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /* 
        11 (1,1) -> 4 (0,2) -> 10 (1,0)
        (2,3) (0,0).  (1,0)(0,0). (1,0)(0,3)
        
        for row iterator: 0 1 2 3 0 1 2 3
        (2,0) -> 8 + 0
        (1,0) -> 4 + 2

        6 / 4 = row
        6 % 4 = col
        */
        int m = matrix.size();
        int n = matrix[0].size();
        int high = m * n - 1;
        int low = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid / n][mid % n] == target) {
                return true;
            }

            if (matrix[mid / n][mid % n] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
