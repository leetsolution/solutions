int maxContainers(int n, int w, int maxWeight) {
    long long totalCells = (long long)n * n;
    long long maxContainersPossible = maxWeight / w;
    
    if (totalCells <= maxContainersPossible) {
        return (int)totalCells;
    } else {
        return (int)maxContainersPossible;
    }
}