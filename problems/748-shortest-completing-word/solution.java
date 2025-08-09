class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        Map<Character, Integer> plateChars = new HashMap<>();
        for (char c : licensePlate.toCharArray()) {
            char lowerC = Character.toLowerCase(c);
            if (Character.isLetter(lowerC)) {
                plateChars.put(lowerC, plateChars.getOrDefault(lowerC, 0) + 1);
            }
        }
        String shortestWord = null;
        for (String word : words) {
            Map<Character, Integer> wordChars = new HashMap<>();
            for (char c : word.toCharArray()) {
                wordChars.put(c, wordChars.getOrDefault(c, 0) + 1);
            }
            boolean completes = true;
            for (Map.Entry<Character, Integer> entry : plateChars.entrySet()) {
                if (!wordChars.containsKey(entry.getKey()) || wordChars.get(entry.getKey()) < entry.getValue()) {
                    completes = false;
                    break;
                }
            }
            if (completes) {
                if (shortestWord == null || word.length() < shortestWord.length()) {
                    shortestWord = word;
                }
            }
        }
        return shortestWord;
    }
}