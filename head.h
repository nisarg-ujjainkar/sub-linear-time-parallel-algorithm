#pragma once
#include<string.h>

int SigBit(int a, int k)
{
	int *sa = new int[64];
	int *start = sa;
	int *end;
	while (a > 0)
	{
		*sa = a % 2;
		a = a / 2;
		sa++;
	}
	end = sa-1;
	sa = sa - 1;
	int i = k - 1;
	int *s = new int[64];
	int *nstart = s;
	while (i >= 0)
	{
		*s = *sa;
		sa--;
		s++;
		i--;
	}
	int *nend = s - 1;
	s = nstart;
	s = nend;
	int j = 0;
	int r = 0;
	while (s != nstart - 1)
	{
		if (j = 0)
			r = r + *s;
		r = r + (*s)*(2 ^ j);
		s--;
		j++;
	}
	return r;
}

int BinToInt(int* sa, int k)
{
	int r = 0;
	for (int i = 0; i < k; ++i)
	{
		int c;
		c= sa[i];
		r = r + c * 2 ^ (k - 1 - i);
	}
	return r;
}

void multiply(int nums[], int T[2][2])
{
	nums[0] = nums[0] * T[0][0] + nums[1] * T[0][1];
	nums[1] = nums[0] * T[1][0] + nums[1] * T[1][1];
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int bit(int a)
{
	int c = 0;
	while (a >= 1)
	{
		++c;
		a = a / 2;
	}
	return c;
}
