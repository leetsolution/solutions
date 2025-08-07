class Solution {
    public String reorderSpaces(String text) {
        int spaceCount = 0;
        int wordCount = 0;
        StringBuilder word = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (c == ' ') {
                spaceCount++;
                if (word.length() > 0) {
                    wordCount++;
                    word.setLength(0);
                }
            } else {
                word.append(c);
            }
        }
        if (word.length() > 0) {
            wordCount++;
        }

        String[] words = text.trim().split("\\s+");

        if (wordCount == 1) {
            return words[0] + " ".repeat(spaceCount);
        }

        int spacesBetween = spaceCount / (wordCount - 1);
        int extraSpaces = spaceCount % (wordCount - 1);

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < words.length - 1; i++) {
            result.append(words[i]);
            result.append(" ".repeat(spacesBetween));
        }
        result.append(words[words.length - 1]);
        result.append(" ".repeat(extraSpaces));

        return result.toString();
    }
}