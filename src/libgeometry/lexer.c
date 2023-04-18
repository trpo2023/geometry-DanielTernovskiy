#include <string.h>

#include <libgeometry/lexer.h>

#define SIZE 100

int checkFigure(char* str)
{
    int ret = 1;
    char rec[SIZE];
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] != '(')
            rec[i] = str[i];

        else
            break;
    }

    char figure[] = "circle";
    if (strcmp(rec, figure) == 0)
        ret = 0;
    return ret;
}
