class Solution {
    public String makeGood(String s) {
        StringBuilder sb = new StringBuilder(s);
        boolean changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < sb.length() - 1; i++) {
                char a = sb.charAt(i);
                char b = sb.charAt(i + 1);
                if (Character.toLowerCase(a) == Character.toLowerCase(b) && a != b) {
                    sb.delete(i, i + 2);
                    changed = true;
                    break;
                }
            }
        }
        return sb.toString();
    }
}