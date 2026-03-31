#include <cmath>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
            Extra hours equals h - numeber of piles
            k = largest number
                iterate array check if its possible to eat all elements
            
            binary search on the k value
            high = largest number
            low. = 0
            for each k you simulate if its possible to eat all elements
                subtract k from elemnt i until <= 0 and decrement h counter
                break if h < 0 while we havnt finished decrementing
                if we can complete then move low upwards
                else move high downwards
        */
        int high = 0;
        std::for_each(piles.begin(), piles.end(), [&](int num) {
            high = std::max(high, num);
        });

        int low = 0;
        int lowest_k = std::numeric_limits<int>::max();
        // perform binary search
        while (low <= high) {
            int k = low + std::ceil((double)((high - low)) / 2);
            // simulate eating
            int track = h;
            bool finished = false;
            std::vector<int> piles_copy = piles;
            for (int i = 0; i < piles.size(); ++i) {
                if (k <= 0) {
                    break;
                }
                track -= std::ceil((double)(piles_copy[i]) / k);
                if (track < 0 || k <= 0) {
                    finished = false;
                    break;
                }
                finished = true;
            }
            std::cout << std::endl;
            
            /*
            low = 13
            high = 25
            k = 25
            track = 0
            */

            if (finished) {
                high = k - 1;
                lowest_k = std::min(k, lowest_k);
            } else {
                low = k + 1;
            }
        }
        return lowest_k;
    }
};
