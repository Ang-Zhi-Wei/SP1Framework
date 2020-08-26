#include "Functions.h"

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

int Sign(int dxy)
{
    if (dxy < 0) return -1;
    else if (dxy > 0) return 1;
    else return 0;
}