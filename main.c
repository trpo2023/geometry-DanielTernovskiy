#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void strToLower(char* str)
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int checkFigure(char* str)
{
    int ret = 1;
    char rec[SIZE];
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '(')
            rec[i] = str[i];
        else
            break;
    }
    char figure[] = "circle";
    if (strcmp(rec, figure) == 0) {
        ret = 0;
    }
    return ret;
}

int main()
{
    FILE* file;
    file = fopen("example.txt", "r");
    char str1[SIZE];
    int countFigures = 0;
    while (fgets(str1, SIZE, file)) {
        countFigures++;
        strToLower(str1);
        printErrors(str1, countFigures);
    }
    fclose(file);
    return 0;
}