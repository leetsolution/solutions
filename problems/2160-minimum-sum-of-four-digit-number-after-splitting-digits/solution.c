int minimumSum(int num) {
    int digits[4];
    digits[0] = num / 1000;
    digits[1] = (num % 1000) / 100;
    digits[2] = (num % 100) / 10;
    digits[3] = num % 10;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (digits[i] > digits[j]) {
                int temp = digits[i];
                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    return (digits[0] + digits[1]) * 10 + digits[2] + digits[3];
}