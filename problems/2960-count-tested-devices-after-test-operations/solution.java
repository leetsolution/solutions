class Solution {
    public int countTestedDevices(int[] batteryPercentages) {
        int testedDevicesCount = 0;
        for (int battery : batteryPercentages) {
            if (battery > testedDevicesCount) {
                testedDevicesCount++;
            }
        }
        return testedDevicesCount;
    }
}