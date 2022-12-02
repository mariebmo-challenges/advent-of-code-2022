#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A();
int B();
int sortTopThree(int *a, int *b, int *c);
void swap(int *pInt, int *pInt1);

int main() {
    // return A();
    return B();
}

int A(){
    FILE* file;
    int bufferLength = 8;
    char buffer[bufferLength];
    int currSum = 0, currId = 0, highSum = 0, highId = 0;

    file = fopen("../input.txt", "r");

    if(file == NULL){
        printf("file can't be read\n");
    }

    while(fgets(buffer, bufferLength, file)){
        if(strcmp(buffer,"\n") == 0){
            if (currSum > highSum){
                highSum = currSum;
                highId = currId;
            }
            currId++;
            currSum = 0;
        } else {
            currSum += atoi(buffer);
        }
    }

    fclose(file);

    printf("Elf %d has the most food with %d kcal\n", highId, highSum);
    return highId;
}

int B(){
    FILE *file;
    int bufferLength = 8;
    char buffer[bufferLength];
    int kcal1 = 0, kcal2 = 0, kcal3 = 0, currKcal = 0;

    file = fopen("../input.txt", "r");

    if(file == NULL){
        printf("file can't be read\n");
    }

    while(fgets(buffer, bufferLength, file)){
        if(strcmp(buffer,"\n") == 0){
            sortTopThree(&kcal1, &kcal2, &kcal3);
            if(currKcal > kcal1){
                kcal3 = kcal2;
                kcal2 = kcal1;
                kcal1 = currKcal;
            } else if (currKcal > kcal2){
                kcal3 = kcal2;
                kcal2 = currKcal;
            } else if (currKcal > kcal3){
                kcal3 = currKcal;
            }

            currKcal = 0;
        } else {
            currKcal += atoi(buffer);
        }
    }

    printf("The top three are %d, %d and %d, with a total of: %d\n", kcal1, kcal2, kcal3, kcal1+kcal2+kcal3);
}

int sortTopThree(int *a, int *b, int *c){

    if(c > a){
        swap(a, c);
    }

    if(b > a){
        swap(a, b);
    }

    if(c > b){
        swap(b, c);
    }
}

void swap(int *pInt, int *pInt1) {
    int temp = *pInt;
    *pInt = *pInt1;
    *pInt1 = temp;
}
