class Solution {
    public String concatHex36(int n) {
        long n2 = (long)n * n;
        long n3 = (long)n * n * n;

        String hex = toHexadecimal(n2);
        String hexatrigesimal = toHexatrigesimal(n3);

        return hex + hexatrigesimal;
    }

    private String toHexadecimal(long num) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            long rem = num % 16;
            if (rem < 10) {
                sb.append(rem);
            } else {
                sb.append((char)('A' + (rem - 10)));
            }
            num /= 16;
        }
        return sb.reverse().toString().isEmpty() ? "0" : sb.reverse().toString();
    }

    private String toHexatrigesimal(long num) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            long rem = num % 36;
            if (rem < 10) {
                sb.append(rem);
            } else {
                sb.append((char)('A' + (rem - 10)));
            }
            num /= 36;
        }
        return sb.reverse().toString().isEmpty() ? "0" : sb.reverse().toString();
    }
}