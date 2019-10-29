#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-5
#define TRUE (1==1)
#define FALSE (!TRUE)
int eq(double a, double b);
/*formula: total year grade= k(# student)/ H^sqrt(n)
   n= years waited
   use search to find #of years grade based on input=> find minimum
*/
double search(double lo, double hi, double student, double h);
double yearsGrade(double student, double h, double year);
int main()
{
    int t, i;
    // k for student and h for hardware factor
    //hi represents the highest year/lifespan of the professor so the max should be around 110 years
    double k, h, lo=0, hi = 110;
    //scan # of input
    scanf("%d", &t);
    for(i = 0; i < t; i++)
    {
        //scan the values
        scanf("%lf %lf", &k, &h);
        //do the ternary search
        double year = search(lo, hi, k, h);
        printf("%lf\n", year);
    }
    return 0;
}
int eq (double a, double b)
{
    // Get the difference
    double diff = a - b;
    if (diff < 0)
        diff = -diff; // absolute value of the difference
    if (diff < EPS)
        return TRUE; // ABSOLUTE ERROR CHECK PASSED
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a < b)
        a = b;
    // Scale the error by the magnitude of the big value
    if (a * EPS > diff)
        return TRUE;
    return FALSE; // Not equal values
}
//ternary search
double search(double lo, double hi, double student, double h)
{
    // Check if the lo and hi value are approximately the same
    if (eq(lo, hi))
        return yearsGrade(student, h, lo);
    //find the 2 mid point
    double m1 = (2 * lo + hi) / 3;
    double m2 = (lo + 2 * hi) / 3;
    //calculate the values at 2 mid point
    double year1 = yearsGrade(student, h, m1);
    double year2 = yearsGrade(student, h, m2);

    if (year1 < year2) {
        //that means values before m1 is better, move high bound to m2
        return search(lo, m2, student, h);
    }
    //means values at m2 is smaller, move low bounds to m1
    return search(m1, hi, student, h);
}
double yearsGrade(double student, double h, double year)
{
    //use the formula to find the time to grade
    double timeGrade= student/pow(h, sqrt(year));
    //add with the wait time to get result
    return year + timeGrade;
}
