class Solution {
    public boolean hasMatch(String s, String p) {
        int starIndex = p.indexOf('*');
        String left = p.substring(0, starIndex);
        String right = p.substring(starIndex + 1);

        for (int i = 0; i <= s.length() - p.length() + 1; i++) {
            if (s.startsWith(left, i)) {
                for (int j = i + left.length(); j <= s.length(); j++) {
                    if (s.substring(j).startsWith(right)) {
                        if (j + right.length() == s.length() - i || s.substring(j).startsWith(right)) {
                            if(j+right.length() >= s.length()-i){
                                if(s.substring(j,s.length()).startsWith(right) || right.isEmpty() )
                                {
                                    return true;
                                }
                            }
                           
                        }
                    }
                }
            }
        }

        return false;
    }
}