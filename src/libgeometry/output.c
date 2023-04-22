#include <stdio.h>
#include <string.h>

#include <libgeometry/area.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>
#include <libgeometry/perimetr.h>

void printStr(char* str)
{
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == '\n')
            break;
        printf("%c", str[i]);
    }
}

int printErrors(char* str, int countFigures)
{
    printf("\nFigure %d:\n", countFigures);
    printStr(str);
    if (checkFigure(str) == 1) {
        printf("\nIncorrect input of figure name\n\n");
    }

    else if (checkArguments(str) == 2) {
        printf("\nFigure coordinates entered incorrectly\n\n");
        return 0;
    }

    else if (checkArguments(str) == 3) {
        printf("\nFigure radius entered incorrectly\n\n");
        return 0;
    }

    else if (checkEnd(str) == 4) {
        printf("\nWrong final symbol\n\n");
        return 0;
    }

    else if (checkEnd(str) == 5) {
        printf("\nWrong final symbol\n\n");
    }

    else
        printf("\n\tarea = %f\n\tperimetr = %f\n",
               calculateArea(str),
               calculatePerimetr(str));
    return 0;
}
