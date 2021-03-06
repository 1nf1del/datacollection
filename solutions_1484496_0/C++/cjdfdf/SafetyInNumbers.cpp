#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h> 
#include <limits.h>
#include <locale.h> 
#include <math.h> 
#include <setjmp.h>
#include <signal.h> 
#include <stdarg.h> 
#include <stddef.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>


bool safetyInNumbersHelper(const std::vector<int>& v, std::vector<int>& ret1, std::vector<int>& ret2)
{
	int n = 1<<(v.size());
	std::map<int, std::vector<int> > m;
	for (int i=1; i<n; ++i)
	{
		std::vector<int> tmp;
		for (unsigned int j=0; j<v.size(); ++j)
		{
			if (i&(1<<j))
				tmp.push_back(v[j]);
		}

		int sum = std::accumulate(tmp.begin(), tmp.end(), 0);
		if (m.find(sum)!=m.end())
		{
			ret1 = m[sum];
			ret2 = tmp;
			return true;
		}
		else
			m[sum] = tmp;
	}

	return false;
}


void safetyInNumbers(const char* filename)
{
	std::ifstream fin;
	fin.open(filename);
	std::ofstream fout;
	std::string str = filename;
	str = str.substr(0, str.size()-3)+".out";
	fout.open(str.c_str());
	int T, N, S;
	fin>>T;

	for (int i=1; i<=T; ++i)
	{
		fin>>N;
		std::vector<int> v;
		for (int j=1; j<=N; ++j)
		{
			fin>>S;
			v.push_back(S);
		}

		std::vector<int> ret1;
		std::vector<int> ret2;
		if (safetyInNumbersHelper(v, ret1, ret2))
		{
			fout<<"Case #"<<i<<":"<<std::endl;
			for (unsigned int k=0; k<ret1.size(); ++k)
				fout<<ret1[k]<<" ";
			fout<<std::endl;

			for (unsigned int k=0; k<ret2.size(); ++k)
				fout<<ret2[k]<<" ";
			fout<<std::endl;

		}
		else
		{
			fout<<"Case #"<<i<<":"<<std::endl;
			fout<<"Impossible"<<std::endl;
		}
	}

	fin.close();
	fout.close();
}



int main()
{
	safetyInNumbers("C-small-attempt0.in");
	return 0;
}
