#include <stdio.h>

int *hasStep(int *a, int size, int step);

int main(){
    int a[] = {1, 2, -3, -1, 5, 5, 2, 5, 2, -1, 2};

    printf("%s step!\n", hasStep(a,11,3) != NULL ? "has" : "does not have");
    return 0;
}

int *hasStep(int *a, int size, int step){
    if (step*2+1 > size){
        return NULL;
    }

    if ((*a == *(a+step)) && (*(a+step) == *(a+2*step))){
        return a;
    }

    return hasStep(a+1, size-1, step);
}
