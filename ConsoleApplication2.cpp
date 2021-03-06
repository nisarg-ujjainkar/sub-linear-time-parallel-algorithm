// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "head.h"

void LongDivide(int nums[])
{
	int a = nums[1], b = nums[2];
	int k = bit(nums[1]) - bit(nums[2]);
	a=SigBit(a, 2 * k);
	a=SigBit(b, k);
	int q = a / b;
	int c = nums[1] - q * nums[2];
	nums[1] = nums[2];
	nums[2] = c;
}

void DoAnIteration(int nums[], int t[2][2], int n)
{
	int l = bit(nums[0]) - bit(nums[1]);
	int p = 0, q = 0;
	int np[64], nq[64];
	if (nums[0] > n*nums[1])
	{
		q = nums[0] / nums[1];
		p = 1;
	}
	else
	{
		for (int i = 0; i < (n*nums[1]) / nums[0]; ++i)
		{
			np[i] = i + 1;
			nq[i] = (np[i] * nums[0]) / nums[1];
			if (np[i] * nums[0] - nq[i] * nums[1] <= (2 * nums[0]) / n && np[i] * nums[0] - nq[i] * nums[1] >= 0)
			{
				p = np[i];
				q = nq[i];
				break;
			}
		}
	}
	t[0][0] = t[0][0] * 0 + t[1][0] * 1;
	t[0][1] = t[0][1] * 0 + t[1][1] * 1;
	t[1][0] = t[0][0] * p - t[1][0] * q;
	t[1][1] = t[0][1] * p - t[1][1] * q;
	multiply(nums, t);
}


void DoAPhase(int nums[], int n)
{
	int m, s;
	double ln = log2(n);
	ln = ln * ln;
	if (bit(nums[0]) > bit(nums[1]))
		m = bit(nums[0]);
	else m = bit(nums[1]);
	s = 2 * ln;
	if (nums[1] > nums[0])
	{
		int temp = nums[0];
		nums[0] = nums[1];
		nums[1] = temp;
	}
	if (bit(nums[0]) - bit(nums[1]) > (ceil(ln)))
	{
		LongDivide(nums);
	}
	else
	{
		int ha, hb, hT;
		int ak = s;
		int bk = s - bit(nums[1]);
		//char sa[64], sb[64];
		//SigBit(sa, nums[1], ak);
		//SigBit(sb, nums[2], bk);
		int a = SigBit(nums[0],ak);
		int b = SigBit(nums[1], bk);
		int nnums[2];
		nnums[0] = a;
		nnums[1] = b;
		ha = bit(a);
		hb = bit(b);
		int T[2][2] = { { 1,0 },{ 0,1 } };
		int endsize = ha + hb - ceil(ln);
		do
		{
			DoAnIteration(nnums, T, n);
			int max = T[0][0];
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					if (T[i][j] > max)
						max = T[i][j];
				}
			}
			hT = bit(max);
		} while (bit(a) + bit(b) >= endsize && hT <= ceil(ln));
		multiply(nums, T);
	}

}


int main()
{
	int nums[2] = { 667,29 };
	int A = nums[0], B = nums[1];
	int ha = bit(nums[0]);
	int hb = bit(nums[1]);
	float x = log2(ha);
	x = x *x;
	int s = ceil(x);
	s = s * 2;
	while (bit(nums[0]) >= s && bit(nums[1]) >= s)
	{
		DoAPhase(nums, ha);
	} 
	int g = GCD(nums[0], nums[1]);
	int g1 = GCD(A, B);
	cout << g1 << '\n' << g;
	_getch();
}

