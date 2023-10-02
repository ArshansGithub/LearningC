#include <stdio.h>
#include <string.h>

struct key_value {
    char key[5]; // Max is 4 characters since "ABC\0"
    char value;
};

int main() {

    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    struct key_value kv[] = {
        {"ABC", '2'},
        {"DEF", '3'},
        {"GHI", '4'},
        {"JKL", '5'},
        {"MNO", '6'},
        {"PQRS", '7'},
        {"TUV", '8'},
        {"WXYZ", '9'}
    };


    int size = sizeof(kv) / sizeof(kv[0]); // Amt of elements
    
    char sample[17]; // Max memory allocated for number 



    printf("Input (Max 15 characters)?\n> "); 
    scanf("%s", sample); 

    if (strlen(sample) >= 15 && sample[14] != '\n') { // too long or should be last character isnt a new line then smthn is wrong
        printf("Input too long! Exiting...");
        return 0;
    }

    for (int eachChar = 0; eachChar < sizeof(sample); eachChar++){
        if (sample[eachChar] == '\0') { // Ignore \0 character
            continue;
        }
        if (strchr(characters, sample[eachChar])) { // Check if even is a character
            for (int i = 0; i < size; i++) { // Go through each element now
                if (strchr(kv[i].key, sample[eachChar])) { // If its a match
                    sample[eachChar] = kv[i].value; // Then replace that specific index!
                }
            }
        }
    }

    printf("Converted: %s", sample);

    return 0;
}