import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numDifferentIntegers(String word) {
        Set<String> distinctIntegers = new HashSet<>();
        StringBuilder currentInteger = new StringBuilder();

        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (Character.isDigit(c)) {
                currentInteger.append(c);
            } else {
                if (currentInteger.length() > 0) {
                    String integerStr = currentInteger.toString();
                    int leadingZeros = 0;
                    while (leadingZeros < integerStr.length() - 1 && integerStr.charAt(leadingZeros) == '0') {
                        leadingZeros++;
                    }
                    distinctIntegers.add(integerStr.substring(leadingZeros));
                    currentInteger = new StringBuilder();
                }
            }
        }

        if (currentInteger.length() > 0) {
            String integerStr = currentInteger.toString();
            int leadingZeros = 0;
            while (leadingZeros < integerStr.length() - 1 && integerStr.charAt(leadingZeros) == '0') {
                leadingZeros++;
            }
            distinctIntegers.add(integerStr.substring(leadingZeros));
        }

        return distinctIntegers.size();
    }
}