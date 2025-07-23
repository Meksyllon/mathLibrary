#include <stdio.h>
//#include <math.h>

#define M_E 2.71828182845904523536

double myTrunc(double x);
double myFabs(double x);
double myCeil(double x);
double myFloor(double x);
double myRound(double x);
double mySqrt(double x);
double myMod(double x, double y);
double myLog(double x);
double myExp(double x);

int main ()
{
	double x = 0;
	scanf("%lf", &x);
	printf("%lf\t%.8lf", x, myLog(x));
	return 0;
}

double myTrunc(double x)
{	
	return (long long)x;
}

double myCeil(double x)
{
	double ceilx = (long long)x;
	if (x > 0 && ceilx != x)
	{
		ceilx++;
	}	
	return ceilx;
}

double myFloor(double x)
{
	double floorx = (long long)x;
	if (x < 0 && floorx != x)
	{
		floorx--;
	}	
	return floorx;
}

double myRound(double x)
{
	double roundedx = (long long)x;
	double remainder = x - roundedx;
	if (remainder >= 0.5)
	{
		roundedx++;
	}
	else
	if (remainder <= -0.5)
	{
		roundedx--;
	}	
	return roundedx;
}

double myFabs(double x)
{
	return x >= 0 ? x : -x;
}

double mySqrt(double x)
{	
	if (x < 0) return 0;
	
	double a = 0;
	double b = x;
	double m = x / 2;

	while (myFabs(x - m * m) > 1e-8)
	{
		if (m * m < x)
		{
			a = m;	
		}
		else
		{
			b = m;
		}		
		m = (a + b) / 2;
	}
	return m;
}

double myMod(double x, double y)
{	
	long long mod = 0;
	mod = x / y;
	long double result = x - mod * y;
	return result;
}

double myLog(double x)
{
	int powInt = 0;
	double powDouble = 0;
	double compare = 0;

	for(; x >= M_E; x /= M_E, powInt++);

	for (int i = 0; i < 100; i++)
	{
		compare = powDouble;
		powDouble = compare + 2 * (x - myExp(compare)) / (x +  myExp(compare));
	}
	return powInt + powDouble;
}

double myExp(double x)
{
	double nextArg = 1;
	double exp = 0;
	for (int i = 1; i < 100; i++)
	{
		exp += nextArg;
		nextArg = nextArg * x / i;
	}	
	return exp;
}