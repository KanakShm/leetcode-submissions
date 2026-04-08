class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        /*
           use a hashmap to store frequencies
           sort the array
           iterate through the array and see if there is another element 
           in the hashmap that is one more than the current
                do this groupSize times and decrement the frequency count
                every time
            if there are no elements one plus the current one and groupSize
            is greater than current size then return false
            iterate i forward
        */
        std::unordered_map<int, int> frequencies;
        for (int i = 0; i < hand.size(); ++i) {
            frequencies[hand[i]]++;
        }

        std::sort(hand.begin(), hand.end(), std::less<int>());
        for (int i = 0; i < hand.size(); ++i) {
            if (frequencies[hand[i]] > 0) {
                for (int j = 0; j < groupSize; ++j) {
                    if (frequencies.find(hand[i] + j) != frequencies.end()) {
                        frequencies[hand[i] + j]--;
                        if (frequencies[hand[i] + j] == 0) frequencies.erase(hand[i] + j);
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
