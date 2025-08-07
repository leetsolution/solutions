class Solution {
    public String decodeMessage(String key, String message) {
        char[] decode = new char[26];
        int index = 0;
        for (char c : key.toCharArray()) {
            if (c != ' ' && decode[c - 'a'] == '\0') {
                decode[c - 'a'] = (char) ('a' + index);
                index++;
            }
        }

        StringBuilder decodedMessage = new StringBuilder();
        for (char c : message.toCharArray()) {
            if (c == ' ') {
                decodedMessage.append(' ');
            } else {
                decodedMessage.append(decode[c - 'a']);
            }
        }

        return decodedMessage.toString();
    }
}