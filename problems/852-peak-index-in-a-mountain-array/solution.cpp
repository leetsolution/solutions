class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2; // mountain peak cannot be at the ends
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1; // should never reach here for valid mountain array
    }
};