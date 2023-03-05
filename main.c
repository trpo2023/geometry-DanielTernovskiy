#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void strtolower(char* str)
{
    for (int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}

int main()
{
    FILE* file;
    file = fopen("example.txt", "r");
    char str1[SIZE];
    int countFigures = 0;
    while (fgets(str1, SIZE, file)) {
        countFigures++;
        strtolower(str1);
        printErrors(str1, countFigures);
    }
    fclose(file);
    return 0;
}