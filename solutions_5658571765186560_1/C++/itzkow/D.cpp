#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;


ifstream fin ("C:\\CodeJam\\2015\\Qualifications\\D\\D-large.in");
ofstream fout ("C:\\CodeJam\\2015\\Qualifications\\D\\D-large.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/



void Solve()
{
	int X,R,C;
	fin>>X>>R>>C;
	
	if ((R*C)%X!= 0)
	{
		fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
		return;
	}

	if (X>=7)
	{
		fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
		return;
	} 
	else if (X==6)
	{
		if (R<=3 || C<=3)
		{
			fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
			return;
		}
		fout << "Case #" << testCase << ": "<<"GABRIEL"<<endl;
		return;
	} 
	else if (X==5)
	{
		if (R<=2 || C<=2)
		{
			fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
			return;
		}
		if (R==3 && C==5)
		{
			fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
			return;
		}
		if (R==5 && C==3)
		{
			fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
			return;
		}
		fout << "Case #" << testCase << ": "<<"GABRIEL"<<endl;
		return;
	} 
	else if (X==4)
	{
		if (R<=2 || C<=2)
		{
			fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
			return;
		}
		fout << "Case #" << testCase << ": "<<"GABRIEL"<<endl;
		return;
	} 
	else if (X==3)
	{
		if (R<=1 || C<=1)
		{
			fout << "Case #" << testCase << ": "<<"RICHARD"<<endl;
			return;
		}
		fout << "Case #" << testCase << ": "<<"GABRIEL"<<endl;
		return;
	} 
	else if (X==2)
	{
		fout << "Case #" << testCase << ": "<<"GABRIEL"<<endl;
		return;
	} 
	else if (X==1)
	{
		fout << "Case #" << testCase << ": "<<"GABRIEL"<<endl;
		return;
	}

	cout<<"ERROR";

}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();
		if (testCase == 1+TestCases/20) {
			cout<<"5%"<<endl;
		} else if (testCase == 1+TestCases/4) {
			cout<<"25%"<<endl;
		} else if (testCase == 1+2*TestCases/4) {
			cout<<"50%"<<endl;
		} else if (testCase == 1+3*TestCases/4) {
			cout<<"75%"<<endl;
		}

	}

	cout<<"100%"<<endl;
	cout<<"finished"<<endl;
	getchar();

}



