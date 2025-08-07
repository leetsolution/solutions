int distMoney(int money, int children) {
    if (money < children) return -1;
    money -= children;
    int count8 = money / 8;
    int remaining = money % 8;
    if (count8 == children && remaining ==0) return children -1;
    if (count8 >= children) return children;
    if (count8 + remaining >= children && count8 < children) return count8;
    if (count8 + remaining < children) return count8;
    return count8;

}