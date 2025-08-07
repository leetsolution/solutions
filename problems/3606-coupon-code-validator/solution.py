class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        valid_coupons = []
        n = len(code)
        for i in range(n):
            if isActive[i]:
                if code[i] != "" and code[i].replace("_", "").isalnum():
                    if businessLine[i] in ["electronics", "grocery", "pharmacy", "restaurant"]:
                        valid_coupons.append((businessLine[i], code[i]))

        valid_coupons.sort(key=lambda x: (["electronics", "grocery", "pharmacy", "restaurant"].index(x[0]), x[1]))
        
        return [coupon[1] for coupon in valid_coupons]