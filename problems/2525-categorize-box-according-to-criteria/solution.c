char* categorizeBox(int length, int width, int height, int mass) {
    long long volume = (long long)length * width * height;
    int bulky = (length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000);
    int heavy = (mass >= 100);
    if (bulky && heavy) return "Both";
    if (bulky) return "Bulky";
    if (heavy) return "Heavy";
    return "Neither";
}