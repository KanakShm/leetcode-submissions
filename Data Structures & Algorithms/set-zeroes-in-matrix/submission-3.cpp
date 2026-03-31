class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            iterate through the matrix top to bottom
            if we see a zero update matrix[0][j] = 0 and matrix[j][0] = 0

            iterate through matrix again and if matrix[0][j] == 0 or matrix[j][0] == 0 then
            set that element to 0

            final step to track matrix[0][0]
        */

        int n = matrix.size();
        int m = matrix[0].size();
        bool row_zero = false;
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0) {
                row_zero = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                matrix[0][0] = 0;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }  

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (row_zero) {
            for (int i = 0; i < m; ++i) {
                matrix[0][i] = 0;
            }
        } 

    }
};
