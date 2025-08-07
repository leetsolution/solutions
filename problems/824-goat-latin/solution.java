class Solution {
    public String toGoatLatin(String sentence) {
        String[] words = sentence.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            char firstChar = word.charAt(0);
            String suffix = "ma";
            if (isVowel(firstChar)) {
                word += suffix;
            } else {
                word = word.substring(1) + firstChar + suffix;
            }
            for (int j = 0; j <= i; j++) {
                word += "a";
            }
            sb.append(word);
            if (i < words.length - 1) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }

    private boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }
}