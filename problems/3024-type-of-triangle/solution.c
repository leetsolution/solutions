char* triangleType(int* nums, int numsSize) {
    if (numsSize != 3) {
        return "none";
    }

    int a = nums[0];
    int b = nums[1];
    int c = nums[2];

    if (a + b <= c || a + c <= b || b + c <= a) {
        return "none";
    }

    if (a == b && b == c) {
        return "equilateral";
    } else if (a == b || a == c || b == c) {
        return "isosceles";
    } else {
        return "scalene";
    }
}