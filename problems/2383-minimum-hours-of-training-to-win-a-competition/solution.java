class Solution {
    public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience) {
        int energyNeeded = 0;
        int experienceNeeded = 0;

        int sumEnergy = 0;
        for (int e : energy) {
            sumEnergy += e;
        }

        if (initialEnergy <= sumEnergy) {
            energyNeeded = sumEnergy - initialEnergy + 1;
        }

        int currentExperience = initialExperience;
        for (int exp : experience) {
            if (currentExperience <= exp) {
                experienceNeeded += (exp - currentExperience + 1);
                currentExperience = exp + 1;
            }
            currentExperience += exp;
        }

        return energyNeeded + experienceNeeded;
    }
}