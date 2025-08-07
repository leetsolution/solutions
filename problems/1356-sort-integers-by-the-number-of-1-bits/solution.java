import java.util.Arrays;

class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] boxedArr = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        Arrays.sort(boxedArr, (a, b) -> {
            int bitCountA = Integer.bitCount(a);
            int bitCountB = Integer.bitCount(b);

            if (bitCountA != bitCountB) {
                return bitCountA - bitCountB;
            } else {
                return a - b;
            }
        });

        return Arrays.stream(boxedArr).mapToInt(Integer::intValue).toArray();
    }
}