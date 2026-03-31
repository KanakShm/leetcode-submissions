class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /*
            sort the people in heaviest to lightest
            start a left pointer at the start
            start righ pointer at the end
            if both are within the limit then ship them together
                update both pointers
            if they are not then ship the heavier one only
                update the left pointer only
            maintain a count of ships
        */

        std::sort(people.begin(), people.end(), std::greater<int>());
        int left = 0;
        int right = people.size() - 1;
        int res = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
                right--;
            } else if (people[left] <= limit) {
                left++;
            }
            res++;
        }
        return res;
    }
};