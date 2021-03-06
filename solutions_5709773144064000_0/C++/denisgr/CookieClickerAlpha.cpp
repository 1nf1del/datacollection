// CookieClickerAlpha.cpp: определяет точку входа для консольного приложения.
//

//#include "2.h"
#include <stdio.h>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <deque>
#include <time.h>
#include <iterator>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

using namespace std;

double findMinTime(double minTime, double currentTime, double C, double F, double X, double cookiesPerSecond)
{
	if (currentTime + X/cookiesPerSecond < minTime)
	{
		minTime = currentTime + X/cookiesPerSecond;
		return findMinTime(minTime, currentTime + C/cookiesPerSecond, C, F, X, cookiesPerSecond + F);
	}
	return minTime;
}

double processTestCase(fstream& inputFile)
{
	double C,F,X;
	inputFile >> C >> F >> X;
	double minTime = X/2.0;
	return findMinTime(X/2.0,C/2.0,C,F,X,F + 2.0);
}
int _tmain(int argc, _TCHAR* argv[])
{
   if (argc != 3)
   {
      std::cerr << "Usage: applicationName inputFileName outputFileName";
      return -1;
   }
   fstream inputFile(argv[1], fstream::in);
   fstream outputFile(argv[2], fstream::out);

   std::string line;
   getline(inputFile, line);
   int testCasesQty = atoi( line.c_str() );
   int testCasesProcessed = 0;
   while (true)
   {
      outputFile << "Case #" << ++testCasesProcessed << ": " << fixed << setprecision(7) << processTestCase(inputFile);
      if (testCasesProcessed == testCasesQty)
         break;
      else
         outputFile  << '\n';
   }
	return 0;
}

