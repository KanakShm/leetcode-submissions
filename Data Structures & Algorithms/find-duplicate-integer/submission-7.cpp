class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
            [5,4,1,2,2]
            have a fast and slow pointer
            slow pointer iterates to the index specified by the element
            fast pointer iterates to the index specified by the index of the element
            break the loop when both values equal each other

            now restart the fast pointer to zero and iterate as if it were slow
            break the loop when both are equal
        */
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (fast == slow) break;
        }

        int slow2 = 0;
        while (true) {
            slow2 = nums[slow2];
            slow = nums[slow];
            if (slow2 == slow) break;
        }

        return slow;

    }
};
