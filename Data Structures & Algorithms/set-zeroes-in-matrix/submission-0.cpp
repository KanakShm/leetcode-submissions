class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            iterate through the array once and record the rows and columns 
            where we need to set a zero.

            go through the matrix again and apply those zeros to the rows and
            columns.
        */
        std::vector<int> rows(matrix.size(), 0);
        std::vector<int> cols(matrix[0].size(), 0);
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == 0) {
                    rows[row] = 1;
                    cols[col] = 1;
                }
            }
        }

        for (int i = 0; i < rows.size(); i++) {
            for (int j = 0; j < cols.size(); j++) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
