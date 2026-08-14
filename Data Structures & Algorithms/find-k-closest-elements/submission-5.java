class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        /*
            find the closest element to start with
            push that and k--
            while k > 0
                check bounds
                increment/decrement the closer value
        */

        int start = 0;
        int min_dist = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; ++i) {
            if (Math.abs(arr[i] - x) < min_dist) {
                start = i;
                min_dist = Math.abs(arr[i] - x);
            }
        }

        int left = start;
        int right = start;
        k--;

        while (k > 0) {
            if (left == 0 && right < arr.length - 1) {
                right++;
            } else if (left > 0 && right == arr.length - 1) {
                left--;
            } else if (left == 0 && right == arr.length - 1) {
                break;
            } else {
                if (Math.abs(arr[left - 1] - x) <= Math.abs(arr[right + 1] - x)) {
                    left--;
                } else {
                    right++;
                }
            }
            k--;
        }

        List<Integer> res = new ArrayList<>();
        while (left <= right) {
            res.add(arr[left]);
            left++;
        }

        return res;
    }
}