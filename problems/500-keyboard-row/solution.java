class Solution {
    public String[] findWords(String[] words) {
        String[] rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        List<String> result = new ArrayList<>();
        for (String word : words) {
            String lowerWord = word.toLowerCase();
            int row = -1;
            boolean found = true;
            for (int i = 0; i < lowerWord.length(); i++) {
                char c = lowerWord.charAt(i);
                int currentRow = -1;
                for (int j = 0; j < rows.length; j++) {
                    if (rows[j].indexOf(c) != -1) {
                        currentRow = j;
                        break;
                    }
                }
                if (row == -1) {
                    row = currentRow;
                } else if (row != currentRow) {
                    found = false;
                    break;
                }
            }
            if (found) {
                result.add(word);
            }
        }
        return result.toArray(new String[0]);
    }
}