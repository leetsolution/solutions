int findPivot(int* arr, int n) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return (l == 0) ? -1 : l - 1;
}

int binarysearch(int* arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int search(int* arr, int n, int target) {
    int pivot = findPivot(arr, n);
    if (pivot == -1) {
        return binarysearch(arr, 0, n - 1, target);
    }
    if (arr[pivot] == target) {
        return pivot;
    }
    if (target >= arr[0]) {
        return binarysearch(arr, 0, pivot - 1, target);
    }
    return binarysearch(arr, pivot + 1, n - 1, target);
}
