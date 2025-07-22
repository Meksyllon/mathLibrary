#include <stdio.h>
#include <math.h>

double myTrunc(double x);
double myFabs(double x);
double myCeil(double x);
double myFloor(double x);

int main ()
{
	double x = 0;
	scanf("%lf", &x);
	printf("%lf\t%lf", x, myFloor(x));
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

}

double myFabs(double x)
{
	return x >= 0 ? x : -x;
}