class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int hours = 0;
        int requiredEnergy = 1;
        for (int i = 0; i < n; ++i) {
            requiredEnergy += energy[i];
        }
        if (initialEnergy < requiredEnergy) {
            hours += (requiredEnergy - initialEnergy);
        }
        int currentExperience = initialExperience;
        for (int i = 0; i < n; ++i) {
            if (currentExperience <= experience[i]) {
                hours += (experience[i] - currentExperience + 1);
                currentExperience = experience[i] + 1;
            }
            currentExperience += experience[i];
        }
        return hours;
    }
};