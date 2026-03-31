class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        /*
            capture a running sum matrix that calculates the sum of each element
            only capture the sum of each row in this prefix sum matrix
        */
        for (int i = 0; i < matrix.size(); ++i) {
            std::vector<int> row;
            int res = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                res += matrix[i][j];
                row.push_back(res);
            }
            prefix.push_back(row);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /*
            for each row from row1 to 2,
                col2 - col1
                then add this result for each row

                26 
                3 0 1 4 5
                5 6 4 3 1
                3 4 3 1 7
                1 4 6 1 5
                
                5 + 13 + 8 = 26
                3  3   4   8   13
                5  11  15  18  19
                3  7   10  11. 18
                1  5.  11. 12. 17

                [3,0,1,4,2]
                [5,6,3,2,1]
                [1,2,0,1,5]
                [4,1,0,1,7]
                [1,0,3,0,5]

        */

        // for (int i = 0; i < prefix.size(); ++i) {
        //     for (int j = 0; j < prefix[0].size(); ++j) {
        //         std::cout << prefix[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        int res = 0;
        while (row1 <= row2) {
            res += prefix[row1][col2];
            if (col1 - 1 >= 0) {
                res -= prefix[row1][col1 - 1];
            }
            row1++;
            // std::cout << res << std::endl;
        }

        return res;
    }

    std::vector<std::vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */