#include <libgeometry/area.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

float calculateArea(char* str)
{
    size_t i = 0;
    char* temp = (char*)malloc(sizeof(char));
    for (i = 0; str[i] != ','; i++)
        ;
    i++;
    int index = 0;
    for (; i < strlen(str); i++) {
        temp[index++] = str[i];
        temp = (char*)realloc(temp, (index + 1) * sizeof(char));
    }
    return M_PI * atof(temp) * atof(temp);
}
