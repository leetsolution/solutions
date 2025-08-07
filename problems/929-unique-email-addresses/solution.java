import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> uniqueEmails = new HashSet<>();
        for (String email : emails) {
            String[] parts = email.split("@");
            String localName = parts[0];
            String domainName = parts[1];
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < localName.length(); i++) {
                char c = localName.charAt(i);
                if (c == '+') {
                    break;
                }
                if (c != '.') {
                    sb.append(c);
                }
            }
            uniqueEmails.add(sb.toString() + "@" + domainName);
        }
        return uniqueEmails.size();
    }
}