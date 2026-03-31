class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
            row i = col n - 1 - i
            col i = row i
            
            make a new copy of matrix array

            iterate through each row and get the full row
            iterate through individual row and assign value to matrix[n-1-i][i]
        */
        vector<vector<int>> result = matrix;
        int n = matrix.size();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                result[col][n - 1 - row] = matrix[row][col];
            }
        }
        matrix = result;
    }
};
