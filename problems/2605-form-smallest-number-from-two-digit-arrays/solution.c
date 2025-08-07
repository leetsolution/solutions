int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int minVal = 10;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            int num1 = nums1[i];
            int num2 = nums2[j];
            int num = 0;
            if (num1 < num2) {
                num = num1 * 10 + num2;
            } else if (num1 > num2) {
                num = num2 * 10 + num1;
            } else {
                num = num1;
            }
            if (num < minVal) {
                minVal = num;
            }
        }
    }
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                if (nums1[i] < minVal)
                    minVal = nums1[i];
            }
        }
    }

    return minVal;
}