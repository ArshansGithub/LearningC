#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int arrlen;
    int* daArray;

    printf("Length?\n> "); 
    scanf("%d", &arrlen);
    
    daArray = (int*) malloc(arrlen * sizeof(int));

    if (daArray == NULL) {
        printf("Couldn't assign memory, sorry lol");
        return 0;
    }

    int i = 0;

    int done = 0;

    printf("\nInput ?\nSay done when finished"); 

    do
    {

        int arr;

        /*for (arr = 0; arr < arrlen; arr++) {
            printf("%d | ", arr);
            printf("Arr: %d\n", daArray[arr]);
        }*/

        char userInput[] = "";

        printf("\n\n> "); 
        scanf("%s", userInput); 

        if (strstr(userInput, "done") != NULL) {
            done = 1;
        }
        else {
            daArray[i] = atoi(userInput);
            i++;
            //printf("%d", atoi(userInput));
        }
    } while (done == 0);


    
    int combo = 0;

    for (int outer = 0; outer < arrlen; outer++){
        //printf("got here");
        //printf("%d\n%d\n", arrlen, daArray[outer]);
        if (daArray[outer] <= 0) {
            //printf("Looping");
            continue;
        }
        //printf("Adding %d with %d\n", combo, daArray[outer]);
        combo += daArray[outer];

    }

    printf("Result: %d", combo);

    return 0;
}

