import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        List<String> validCoupons = new ArrayList<>();
        Map<String, Integer> businessLineOrder = new HashMap<>();
        businessLineOrder.put("electronics", 1);
        businessLineOrder.put("grocery", 2);
        businessLineOrder.put("pharmacy", 3);
        businessLineOrder.put("restaurant", 4);

        List<Coupon> coupons = new ArrayList<>();

        for (int i = 0; i < code.length; i++) {
            if (isValidCoupon(code[i], businessLine[i], isActive[i])) {
                coupons.add(new Coupon(code[i], businessLine[i]));
            }
        }

        Collections.sort(coupons, (a, b) -> {
            int businessLineComparison = Integer.compare(businessLineOrder.get(a.businessLine), businessLineOrder.get(b.businessLine));
            if (businessLineComparison != 0) {
                return businessLineComparison;
            } else {
                return a.code.compareTo(b.code);
            }
        });

        for (Coupon coupon : coupons) {
            validCoupons.add(coupon.code);
        }

        return validCoupons;
    }

    private boolean isValidCoupon(String code, String businessLine, boolean isActive) {
        if (code == null || code.isEmpty()) {
            return false;
        }

        for (char c : code.toCharArray()) {
            if (!Character.isLetterOrDigit(c) && c != '_') {
                return false;
            }
        }

        if (!businessLine.equals("electronics") && !businessLine.equals("grocery") &&
                !businessLine.equals("pharmacy") && !businessLine.equals("restaurant")) {
            return false;
        }

        return isActive;
    }

    private static class Coupon {
        String code;
        String businessLine;

        public Coupon(String code, String businessLine) {
            this.code = code;
            this.businessLine = businessLine;
        }
    }
}