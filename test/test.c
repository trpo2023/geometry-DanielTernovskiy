#include <ctest.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <libgeometry/area.h>
#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>
#include <libgeometry/perimetr.h>

CTEST(check_right_figure, test1)
{
    char* str = "circle(2.3, 3.2, 4.0)";
    const int expected = 0;
    const int result = checkFigure(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_incroorect_figure, test2)
{
    char* str = "ciirrcle(2.3, 3.2, 4.0)";
    const int excpected = 1;
    const int result = checkFigure(str);
    ASSERT_EQUAL(excpected, result);
}

CTEST(check_int_arg, test3)
{
    char* str = "circle(1 2, 3)";
    const int expected = 0;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_float_arg, test4)
{
    char* str = "circle(1.0 2.0, 3.0)";
    const int expected = 0;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_diff_arg, test5)
{
    char* str = "circle(1 2, 3.0)";
    const int expected = 0;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_incorrect_arg, test6)
{
    char* str = "circle(x 2.0, 3.0)";
    const int expected = 2;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_incorrect_arg, test7)
{
    char* str = "circle(2.0 x, 3.0)";
    const int expected = 2;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_incorrect_arg, test8)
{
    char* str = "circle(2.0 3.0, X)";
    const int expected = 3;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_end_bracket, test9)
{
    char* str = "circle(1.0 2.0, 3.0)\n ";
    const int expected = 0;
    const int result = checkEnd(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_incorrect_end_bracket, test10)
{
    char* str = "circle(2.0 2.0, 3.0(";
    const int expected = 4;
    const int result = checkEnd(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_right_area, test11)
{
    char* str = "circle(2 2, 3)";
    const double expected = 9 * M_PI;
    const double result = calculateArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_incorrect_area, test12)
{
    char* str = "circle(2 2, x)";
    const double expected = -1;
    const double result = calculateArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}

CTEST(check_right_perimetr, test13)
{
    char* str = "circle(2 2, 3)";
    const double expected = 2 * M_PI * 3;
    const double result = calculatePerimetr(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_incorrect_perimetr, test14)
{
    char* str = "circle(2 2, x)";
    const double expected = -1;
    const double result = calculatePerimetr(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}
