int minNumberOfHours(int initialEnergy, int initialExperience, int* energy, int energySize, int* experience, int experienceSize) {
    int trainingHours = 0;
    int currentEnergy = initialEnergy;
    int currentExperience = initialExperience;

    for (int i = 0; i < energySize; i++) {
        if (currentEnergy <= energy[i]) {
            trainingHours += (energy[i] - currentEnergy + 1);
            currentEnergy = energy[i] + 1;
        }
        currentEnergy -= energy[i];

        if (currentExperience <= experience[i]) {
            trainingHours += (experience[i] - currentExperience + 1);
            currentExperience = experience[i] + 1;
        }
        currentExperience += experience[i];
    }

    return trainingHours;
}