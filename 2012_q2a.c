#include <stdio.h>

#define N 20

typedef struct {
    int array[N];   //array[1000] -----> [][][][][][][][][][]
    int len;
} Arr;

int *hasStep(int *a, int size, int step);


int checkHasStep(Arr arr);

void initArr(Arr *a);

int main(){
    Arr arr;        // trash value
    int sequenceValue;

    initArr(&arr);

    sequenceValue = checkHasStep(arr);

    if (sequenceValue == 0){
        printf("no sequence mate\n");
    } else {
        printf("found sequence with value %d\n", sequenceValue);
    }
    return 0;
}

void initArr(Arr *a) {
    int input;
    int i;

    printf("enter array values (0 to quit): ");

    for(i=0; (scanf("%d",&input) != EOF) && (i<N); i++){
        a->array[i] = input;
    }
    a->len = i;
}

/*  returns value of step as received by user, 0 otherwise
 * */
int checkHasStep(Arr arr) {
    int step;
    int *loc;

    /*  get step from user  */
    printf("enter step:\n");
    scanf("%d",&step);

    /*  get pointer to beginning for sequence   */
    loc = hasStep(arr.array, arr.len, step);

    /*  return 0 of no sequence found, */
    return loc != NULL ? *loc : 0;
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
