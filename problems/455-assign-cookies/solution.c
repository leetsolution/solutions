int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), [](const void *a, const void *b){
        return *(int*)a - *(int*)b;
    });
    qsort(s, sSize, sizeof(int), [](const void *a, const void *b){
        return *(int*)a - *(int*)b;
    });
    int i = 0, j = 0;
    int count = 0;
    while(i < gSize && j < sSize){
        if(s[j] >= g[i]){
            count++;
            i++;
            j++;
        }else{
            j++;
        }
    }
    return count;
}