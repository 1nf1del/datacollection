#include <iostream>
#include <string>
#include <string>
#include <fstream>

using namespace std;

int mat[16] = {0, 1, 2, 3, 
			   1, 0, 3, 2,
			   2, 3, 0, 1,
			   3, 2, 1, 0};

int signmat[16] = { 1, 1, 1, 1,
					1,-1, 1,-1,
					1,-1,-1, 1,
					1, 1,-1,-1 };

int divsign[16] = { 1,-1,-1,-1,
					1, 1, 1,-1,
					1,-1, 1, 1,
					1, 1,-1, 1 };

int mul[100001];
int muls[100001];
int l;
int rsize = 0;

int icc[10001];

void mnog(int a, int as, int b, int bs, int& c, int& cs)
{
	c = mat[4 * a + b];
	cs = signmat[4 * a + b] * as*bs;
}

void div(int a, int as, int b, int bs, int& c, int& cs)
{
	c = mat[4 * a + b];
	cs = divsign[4 * a + b]*as*bs;
}

void compmul()
{
	mul[0] = 0;
	muls[0] = 1;
	for (size_t i = 1; i <= rsize+1; i++)
		mnog(mul[i-1], muls[i-1], icc[(i-1)%l], 1, mul[i], muls[i]);
}

void mulmnog(int be, int en, int &c, int& cs)
{
	div(mul[en + 1], muls[en + 1], mul[be], muls[be], c, cs);
}

int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/C-small-attempt2.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output2.txt");

	ifile >> T;

	for (size_t i = 0; i < T; i++)
	{
		long long x;
		ifile >> l >> x;

		string cc;
		ifile >> cc;

		for (size_t j = 0; j < l; j++)
		{
			if (cc.at(j) == 'i') icc[j] = 1;
			if (cc.at(j) == 'j') icc[j] = 2;
			if (cc.at(j) == 'k') icc[j] = 3;
		}

//		if (x < 9)
			rsize = l*x;
//		else if (x % 2 == 0)
//			rsize = 8 * l;
//		else
//			rsize = 9 * l;

		if (rsize < 3)
		{
			ofile << "Case #" << i + 1 << ": NO" << endl;
			continue;
		}

		compmul();

		bool tt = false;
		for (size_t i1 = 0; (i1 < rsize - 2); i1++)
		{
			int c, cs;
			mulmnog(0, i1, c, cs);
			if (c == 1 && cs == 1)
				for (size_t i2 = i1 + 1; (i2 < rsize - 1); i2++)
				if (!tt)
				{
					mulmnog(i1+1, i2, c, cs);
					if (c == 2 && cs == 1)
					{
						mulmnog(i2+1, rsize-1, c, cs);
						if (c == 3 && cs == 1)
						{
							tt = true;
							break;
						}
					}
				}
			if (tt)
				break;
		}

		if (tt)
			ofile << "Case #" << i + 1 << ": YES" << endl;
		else
			ofile << "Case #" << i + 1 << ": NO" << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}


/*
int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/A-large.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output1.txt");

	ifile >> T;

	for (size_t i = 0; i < T; i++)
	{
		int ss;
		ifile >> ss;

		string cc;
		ifile >> cc;

		int cur_stand = int(cc.at(0) - '0');
		int ans = 0;
		for (size_t j = 1; j <= ss; j++)
		{
			if (int(cc.at(j) - '0') > 0 && cur_stand < j)
			{
				ans += j - cur_stand;
				cur_stand += j - cur_stand;
			}

			cur_stand += int(cc.at(j) - '0');
		}

		ofile << "Case #" << i+1 << ": " << ans << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}

*/