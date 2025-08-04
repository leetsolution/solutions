int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (mid % 2 == 1) mid--;
        if (nums[mid] == nums[mid+1]) {
            l = mid + 2;
        } else {
            r = mid;
        }
    }
    return nums[l];
}
