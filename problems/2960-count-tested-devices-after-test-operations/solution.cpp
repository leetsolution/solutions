class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int testedDevicesCount = 0;
        for (int percentage : batteryPercentages) {
            if (percentage > testedDevicesCount) {
                testedDevicesCount++;
            }
        }
        return testedDevicesCount;
    }
};