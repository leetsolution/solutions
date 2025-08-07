class Solution {
    public String getEncryptedString(String s, int k) {
        StringBuilder encryptedString = new StringBuilder();
        for (char c : s.toCharArray()) {
            int newChar = ((c - 'a' + k) % 26) + 'a';
            encryptedString.append((char)newChar);
        }
        return encryptedString.toString();
    }
}