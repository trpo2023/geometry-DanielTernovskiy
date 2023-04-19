#include <ctest.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

#include <libgeometry/area.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>
#include <libgeometry/perimetr.h>

CTEST(check_figure, test1)
{
    char* str = "circle(2.3, 3.2, 4.0)";

    const int expected = 0;

    const int result = checkFigure(str);

    ASSERT_EQUAL(expected, result);
}

CTEST(check_figure, test2)
{
    char* str = "ciirrcle(2.3, 3.2, 4.0)";
    const int excpected = 1;
    const int result = checkFigure(str);
    ASSERT_EQUAL(excpected, result);
}