class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        java.util.HashMap<Character, Character> mapST = new java.util.HashMap<>();
        java.util.HashMap<Character, Character> mapTS = new java.util.HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char charS = s.charAt(i);
            char charT = t.charAt(i);

            if (mapST.containsKey(charS)) {
                if (mapST.get(charS) != charT) {
                    return false;
                }
            } else {
                if (mapTS.containsKey(charT)) {
                    return false;
                }
                mapST.put(charS, charT);
                mapTS.put(charT, charS);
            }
        }

        return true;
    }
}