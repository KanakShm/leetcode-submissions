class Solution {
public:
    vector<int> countBits(int n) {
        /*
            keep counting upwards to n
            while the number is not zero count 1s
                bit shift right 1 every loop
        */
        std::vector<int> output;
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int num = i;
            while (num) {
                if (num & 1) count++;
                num = num >> 1;
            }
            output.push_back(count);
        }
        return output;
    }   
};
