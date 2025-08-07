bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), [](const void *a, const void *b){
        return *(int*)a - *(int*)b;
    });
    int diff = arr[1] - arr[0];
    for(int i = 2; i < arrSize; i++){
        if(arr[i] - arr[i-1] != diff) return false;
    }
    return true;
}