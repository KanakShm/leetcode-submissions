class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
            keep track of visited array
            if visited replace with INT_MIN
            keep track of curr direction
                if next element is visited
                    if up then go right
                    if right then go down
                    if down then go left
                    if left then go up
        */
        enum Direction {
            UP,
            RIGHT,
            DOWN,
            LEFT
        };

        enum Direction direction = Direction::RIGHT;
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = 0;
        std::vector<int> output;
        while (count < m * n) {
            output.push_back(matrix[i][j]);
            matrix[i][j] = INT_MIN;
            count++;
            if (direction == Direction::RIGHT) {
                if (j + 1 == n || matrix[i][j + 1] == INT_MIN) {
                    direction = Direction::DOWN;
                    i++;
                } else {
                    j++;
                }
            } else if (direction == Direction::DOWN) {
                if (i + 1 >= m || matrix[i + 1][j] == INT_MIN) {
                    direction = Direction::LEFT;
                    j--;
                } else {
                    i++;
                }
            } else if (direction == Direction::LEFT) {
                if (j - 1 < 0 || matrix[i][j - 1] == INT_MIN) {
                    direction = Direction::UP;
                    i--;
                } else {
                    j--;
                }
            } else if (direction == Direction::UP) {
                if (i - 1 < 0 || matrix[i - 1][j] == INT_MIN) {
                    direction = Direction::RIGHT;
                    j++;
                } else {
                    i--;
                }
            }
        }
        return output;
    }
};
