class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        /*
            Each node in matrix represents the prefix sum of the square enclosed by it
            and the top left element
        */
        prefix.resize(matrix.size() + 1, std::vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            // get row sum. add it to the element directly above
            int running_sum = 0;
            for (int j = 0; j < matrix[0].size(); ++j) {
                running_sum += matrix[i][j];
                if (i + 1 < prefix.size() && j + 1 < prefix[0].size()) {
                    prefix[i + 1][j + 1] = running_sum + prefix[i][j + 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /*
            The sum will be whatevre is at row2 col2 - above row1 - before col1
            add whatever is row1-1 col1-1
            [3,0,1,4,2]
            [5,6,3,2,1]
            [1,2,0,1,5]
            [4,1,0,1,7]
            [1,0,3,0,5]

            1
        */

        for (int i = 0; i < prefix.size(); ++i) {
            for (int j = 0; j < prefix[0].size(); ++j) {
                std::cout << prefix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        int full = prefix[row2 + 1][col2 + 1];
        if (row1 >= 0) {
            full -= prefix[row1][col2 + 1];
        }
        if (col1 >= 0) {
            full -= prefix[row2 + 1][col1];
        }

        if (col1 >= 0 && row1 >= 0) {
            full += prefix[row1][col1];
        }

        return full;
    }

    std::vector<std::vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */