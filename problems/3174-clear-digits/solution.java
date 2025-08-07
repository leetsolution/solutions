class Solution {
    public String clearDigits(String s) {
        StringBuilder sb = new StringBuilder(s);
        while (true) {
            boolean removed = false;
            for (int i = 0; i < sb.length(); i++) {
                if (Character.isDigit(sb.charAt(i))) {
                    boolean foundLeft = false;
                    for (int j = i - 1; j >= 0; j--) {
                        if (!Character.isDigit(sb.charAt(j))) {
                            sb.deleteCharAt(i);
                            sb.deleteCharAt(j);
                            removed = true;
                            foundLeft = true;
                            break;
                        }
                    }
                    if (foundLeft) {
                        break;
                    }
                }
            }
            if (!removed) {
                break;
            }
        }
        return sb.toString();
    }
}