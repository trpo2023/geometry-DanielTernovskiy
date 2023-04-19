#include <stdio.h>
#include <string.h>

#include <libgeometry/area.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>
#include <libgeometry/perimetr.h>

int checkArguments(char* str)
{
    int count = 0;
    for (size_t i = 7; str[i] != ',' && i < strlen(str); i++) {
        if ((str[i] != '.' && str[i] != ' ')
            && !(str[i] >= 48 && str[i] <= 57)) {
            return 1;
        }
        if (str[i] >= 48 && str[i] <= 57 && str[i + 1] == ' ')
            count++;
        if (str[i] == '.' && str[i + 1] == ')')
            count += 2;
    }

    if (count + 1 != 2) {
        return 1;
    }

    size_t index = 0;
    for (size_t i = 0; i != strlen(str); i++) {
        if (str[i] == ',') {
            index = i + 1;
            i = strlen(str) - 1;
        }
    }

    for (; str[index] != ')' && index < strlen(str); index++) {
        if ((str[index] != '.' && str[index] != ' ')
            && !(str[index] >= 48 && str[index] <= 57)) {
            return 2;
        }
        if (str[index] >= 48 && str[index] <= 57 && str[index + 1] == ' ')
            count++;
        if (str[index] == '.' && str[index + 1] == ' ')
            count += 2;
    }

    if (count != 1) {
        return 2;
    }
    return 0;
}

int checkEnd(char* str)
{
    int firstBracket = 0;
    int endingSymbol;
    if (str[strlen(str) - 1] == '\n')
        endingSymbol = strlen(str) - 2;
    else
        endingSymbol = strlen(str) - 1;

    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == ')') {
            firstBracket = i;
            break;
        }
    }

    if (firstBracket == endingSymbol)
        return 0;
    return 1;
}

int printErrors(char* str, int countFigures)
{
    printf("Figure %d:\n", countFigures);
    printf("%s", str);
    if (checkFigure(str) == 1) {
        printf("Incorrect input of figure name\n\n");
    }

    else if (checkArguments(str) == 1) {
        printf("Figure coordinates entered incorrectly\n\n");
        return 0;
    }
    
    else if (checkArguments(str) == 2) {
        printf("Figure radius entered incorrectly\n\n");
        return 0;
    }

    else if (checkEnd(str) == 1) {
        printf("Wrong final symbol\n\n");
    }

    else
        printf("\n\tarea = %f\n\tperimetr = %f",
               calculateArea(str),
               calculatePerimetr(str));
    return 0;
}
