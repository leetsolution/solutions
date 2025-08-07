class Solution:
    def minNumberOfHours(self, initialEnergy: int, initialExperience: int, energy: List[int], experience: List[int]) -> int:
        energy_needed = 0
        for e in energy:
            if initialEnergy <= e:
                energy_needed += (e - initialEnergy + 1)
                initialEnergy = e + 1
            initialEnergy -= e
        
        experience_needed = 0
        curr_experience = initialExperience
        for exp in experience:
            if curr_experience <= exp:
                experience_needed += (exp - curr_experience + 1)
                curr_experience = exp + 1
            curr_experience += exp
        
        return energy_needed + experience_needed