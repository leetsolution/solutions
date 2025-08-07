class Solution {
    public String generateTag(String caption) {
        String[] words = caption.split(" ");
        StringBuilder sb = new StringBuilder("#");

        if (words.length > 0) {
            sb.append(words[0].toLowerCase());
            for (int i = 1; i < words.length; i++) {
                String word = words[i];
                if (word.length() > 0) {
                    sb.append(Character.toUpperCase(word.charAt(0)));
                    if (word.length() > 1) {
                        sb.append(word.substring(1).toLowerCase());
                    }
                }
            }
        }

        StringBuilder result = new StringBuilder();
        result.append("#");
        for (int i = 1; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (Character.isLetter(c)) {
                result.append(c);
            }
        }

        if (result.length() > 100) {
            return result.substring(0, 100);
        } else {
            return result.toString();
        }
    }
}