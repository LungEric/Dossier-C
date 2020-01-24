#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student{
    char *name;
    int  studentNumber;
} Student;

int main(void)
{
    char *string;
    char *tok;
    Student acolyte;

    // set up the input, like this to show use of `strdup` and `free`
    string = strdup("Tommy-1234567");       // allocate memory for source string
    if (string == NULL)                     // check it worked
        return 1;                           // failure

    // student name
    tok = strtok(string, "-");              // isolate first token
    if (tok == NULL)                        // check it worked
        return 1;                           // failure
    acolyte.name = strdup(tok);             // allocated mem for substring and copy
    if (acolyte.name == NULL)               // check it worked
        return 1;                           // failure

    // student number
    tok = strtok(NULL, "-");                // isolate next token
    if (tok == NULL)                        // check it worked
        return 1;                           // failure
    if (sscanf(tok, "%d", &acolyte.studentNumber) != 1)     // extract int
        return 1;                           // failure

    free(string);                           // can now get rid of source data

    // show result
    printf("Name: %s\n", acolyte.name);
    printf("Number: %d\n", acolyte.studentNumber);
    free(acolyte.name);                     // free the memory in struct
    return 0;
}
