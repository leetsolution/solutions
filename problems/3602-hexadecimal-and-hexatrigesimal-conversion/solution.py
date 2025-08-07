class Solution:
    def concatHex36(self, n: int) -> str:
        def to_hex(num):
            hex_digits = "0123456789ABCDEF"
            if num == 0:
                return "0"
            hex_str = ""
            while num > 0:
                remainder = num % 16
                hex_str = hex_digits[remainder] + hex_str
                num //= 16
            return hex_str

        def to_hexatrigesimal(num):
            hexatrigesimal_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            if num == 0:
                return "0"
            hexatrigesimal_str = ""
            while num > 0:
                remainder = num % 36
                hexatrigesimal_str = hexatrigesimal_digits[remainder] + hexatrigesimal_str
                num //= 36
            return hexatrigesimal_str

        n_squared = n * n
        n_cubed = n * n * n

        hex_representation = to_hex(n_squared)
        hexatrigesimal_representation = to_hexatrigesimal(n_cubed)

        return hex_representation + hexatrigesimal_representation