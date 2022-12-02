#include <stdio.h>

int A();
int B();
int calculateScore(char *line);
int calculateTypeScore(char *line);
int scoreFromChar(char letter);
char translateChar(char letter);

int main() {
    //A();
    B();
    return 0;
}

int A(){
    FILE *file;
    int currScore = 0;
    int bufferLength = 8;
    char buffer[bufferLength];

    file = fopen("../input.txt", "r");

    if (file == NULL) {
        printf("Error opening file");
    }

    while(fgets(buffer, bufferLength, file)){
        //printf("%s", buffer);
        currScore += calculateScore(buffer);
    }

    printf("max score is: %d", currScore);
    return currScore;
}

int B(){
    FILE *file;
    int currScore = 0;
    int bufferLength = 8;
    char buffer[bufferLength];

    file = fopen("../input.txt", "r");

    if (file == NULL) {
        printf("Error opening file");
    }

    while(fgets(buffer, bufferLength, file)){
        //printf("%s", buffer);
        currScore += calculateTypeScore(buffer);
    }

    printf("max score is: %d", currScore);
    return currScore;
}

int calculateScore(char *line){
    int score = 0;
    char their, our;

    their = line[0];
    our = translateChar(line[2]);

    if(their == our){
        score += 3;
        score += scoreFromChar(our);
        printf("It's a tie! they:%c, us:%c. Score: %d\n", their, our, score);
    } else if (their == 'A' && our == 'B'){
        score += 6;
        score += scoreFromChar(our);
        printf("We won! they:%c, us:%c. Score: %d\n", their, our, score);
    } else if (their == 'B' && our == 'C'){
        score += 6;
        score += scoreFromChar(our);
        printf("We won! they:%c, us:%c. Score: %d\n", their, our, score);
    } else if (their == 'C' && our == 'A'){
        score += 6;
        score += scoreFromChar(our);
        printf("We won! they:%c, us:%c. Score: %d\n", their, our, score);
    } else {
        score += scoreFromChar(our);
        printf("We lost. they:%c, us:%c. Score: %d\n", their, our, score);
    }

    return score;
}

int calculateTypeScore(char *line){
    int score = 0;
    char their, state;

    their = line[0];
    state = line[2];

    if(state == 'X'){
        switch(their){
            case 'A': score += 3;
                break;
            case 'B': score += 1;
                break;
            case 'C': score += 2;
                break;
            default: score += 0;
                break;
        }
    } else if (state == 'Y'){
        score += scoreFromChar(their);
        score += 3;
    } else if (state == 'Z'){
        switch (their) {
            case 'A': score += 2;
                break;
            case 'B': score += 3;
                break;
            case 'C': score += 1;
                break;
            default: score += 0;
        }

        score += 6;
    }

    return score;
}

int scoreFromChar(char letter){
    switch (letter) {
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        default: return 0;
    }
}
char translateChar(char letter){
    switch (letter) {
        case 'X': return 'A';
        case 'Y': return 'B';
        case 'Z': return 'C';
        default: return 'Q';
    }
}