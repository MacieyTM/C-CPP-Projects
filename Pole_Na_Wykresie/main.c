#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define lp 1000
#define n 10000

double c_od, c_do, krok, calka;
int i;

/*
double f3(double x)
{
return -1;
}

double f4(double x)
{
return 1;
}
*/

double prostokaty(double(*f)(double))
{
    calka=0;
    krok=(c_do-c_od)/lp;
    for(i=1; i<=lp; i=i+1)
        calka=calka+f(c_od+i*krok);
    calka=calka*krok;
    return calka;
}

double trapezy(double(*f)(double))
{
    double x;
    krok=(c_do-c_od)/lp;
    calka=1./2*(f(c_od)+f(c_do));
    for(x=c_od+krok; x<c_do; x=x+krok)
        calka=calka+f(x);
    calka=calka*krok;
    return calka;
}

double mc(double(*f)(double))
{
    double zakresx;
//    srand(time(NULL));
    calka=0;
    zakresx=c_do-c_od;
    for(i=1; i<=n; i=i+1)
        calka=calka+f(c_od+((double)rand()/(double)(RAND_MAX/*+1*/)*zakresx));
    calka=zakresx*calka/n;
    return calka;
}

double f1(double x)
{
    return 2;
}

double f2(double x)
{
    return 2*x;
}

double f3(double x)
{
    return 2*x*x;
}

double f4(double x)
{
	return 2*x*x*x;
}

int main(int argc, char *argv[])
{
    printf("od=");
    scanf("%lf", &c_od);
    printf("do=");
    scanf("%lf", &c_do);
    printf("\n\nFunkcja 1\n");
    printf("wynik prostokaty - %lf\n", prostokaty(f1));
    printf("wynik trapezy    - %lf\n", trapezy(f1));
    printf("wynik MC         - %lf\n", mc(f1));
    printf("\n\nFunkcja 2\n");
    printf("wynik prostokaty - %lf\n", prostokaty(f2));
    printf("wynik trapezy    - %lf\n", trapezy(f2));
    printf("wynik MC         - %lf\n", mc(f2));
    printf("\n\nFunkcja 3\n");
    printf("wynik prostokaty - %lf\n", prostokaty(f3));
    printf("wynik trapezy    - %lf\n", trapezy(f3));
    printf("wynik MC         - %lf\n", mc(f3));
    printf("\n\nFunkcja 4\n");
    printf("wynik prostokaty - %lf\n", prostokaty(f4));
    printf("wynik trapezy    - %lf\n", trapezy(f4));
    printf("wynik MC         - %lf\n", mc(f4));
//    system("PAUSE");

    return 0;
}
