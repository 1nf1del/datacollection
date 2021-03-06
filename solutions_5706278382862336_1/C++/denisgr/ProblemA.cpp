// ProblemA.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

string processTestCase(fstream& inputFile)
{
	string s;
	inputFile >> s;
	string P, Q;
	ll pos = s.find('/');
	P = s.substr(0,pos);
	Q = s.substr(pos+1);
	ll p = _atoi64(P.c_str()), q = _atoi64(Q.c_str());
	ll result;
	ll newp = p;
	for (ll i = 1; i <= 40; ++i)
	{
		ll curr = newp * 2;
		if (curr == q)
		{
			ostringstream oss;
			oss << i;
			return oss.str();
		}
		else if (curr > q)
		{
			result = i;
			newp = curr - q;
			break;
		}
		else
		{
			newp = curr;
		}
	}
	for (ll i = result; i <= 40; ++i)
	{
		ll curr = newp * 2;
		if (curr == p)
		{
			break;
		}
		if (curr == q)
		{
			ostringstream oss;
			oss << result;
			return oss.str();
		}
		else
		{
			newp = curr;
			newp %= q;
		}
	}
	return string("impossible");
	
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
      outputFile << "Case #" << ++testCasesProcessed << ": " << processTestCase(inputFile);
      if (testCasesProcessed == testCasesQty)
         break;
      else
         outputFile  << '\n';
   }
	return 0;
}

