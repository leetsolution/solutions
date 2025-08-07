class Solution {
    public int largestInteger(int num) {
        String s = Integer.toString(num);
        char[] chars = s.toCharArray();
        List<Character> odd = new ArrayList<>();
        List<Character> even = new ArrayList<>();
        for (char c : chars) {
            if ((c - '0') % 2 == 0) {
                even.add(c);
            } else {
                odd.add(c);
            }
        }
        Collections.sort(odd, Collections.reverseOrder());
        Collections.sort(even, Collections.reverseOrder());
        int i = 0, j = 0;
        for (int k = 0; k < chars.length; k++) {
            if ((chars[k] - '0') % 2 == 0) {
                chars[k] = even.get(i++);
            } else {
                chars[k] = odd.get(j++);
            }
        }
        return Integer.parseInt(new String(chars));
    }
}