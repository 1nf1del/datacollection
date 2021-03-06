/*
ID:
PROG: kimbits
LANG: C++
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stdio.h>
#include <cstdlib>
#include <unordered_set>
#include <memory.h>
#include <ctime>
#include <stack>
#include <unordered_map>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif


const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-9;
const int INF = 2000000000;

#pragma comment(linker, "/stack:1500000000")
#define sz size()
#define mp make_pair
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MEMS(a,b) memset(a,b,sizeof(a))
#define sqr(a) ((a)*(a))
#define HAS(a,b) ((a).find(b)!=(a).end())
#define MAX(a,b) ((a>=b)?a:b)
#define MIN(a,b) ((a<=b)?a:b)
#define ABS(a) ((a<0)?-(a):a)
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define FORD(i,a,b) for (int i=(a);i>(b);--i)
#define VVI vector < vector <int> >
#define VI vector <int>
#define LL long long    
#define U unsigned
#define pnt pair <int,int>
LL gcd(LL a, LL b){ if (a == 0) return b; return gcd(b%a, a); }
LL lcm(LL a, LL b){ return a / gcd(a, b) * b; }

using namespace std;

void ifd() {
#ifdef SAMMAX
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	beg = clock();
#else
	//freopen("kimbits.in", "r", stdin);
	//freopen("kimbits.out", "w", stdout);
#endif  
}
void tme() {
#ifdef SAMMAX
	fprintf(stderr, "*** Total time: %.3lf ***\n", 1.0*(clock() - beg) / CLOCKS_PER_SEC);
#endif
}

int t, ans, n, d, h, m;
vector<pair<int, int> > hikers;

int main() {
	ifd();

	cin >> t;
	
	FOR(tc, 1, t + 1) {
		hikers.clear();
		cin >> n;
		FOR(i, 0, n) {
			cin >> d >> h >> m;
			FOR(j, 0, h) {
				hikers.push_back(make_pair(d, m + j));
			}
		}
		if (hikers.size() < 2) {
			printf("Case #%d: %d\n", tc, 0);
		}
		else {
			if (hikers[0].second == hikers[1].second) {
				if (hikers[0].first > hikers[1].first)
					swap(hikers[0], hikers[1]);
			} else if (hikers[0].second < hikers[1].second)
				swap(hikers[0], hikers[1]);

			//FOR(i, 0, hikers.size())
			//	cout << hikers[i].first << ": " << hikers[i].second << "\n";

			LL d0 = 360 - hikers[0].first;
			LL d1 = 360 + (360 - hikers[1].first);

			LL t1 = 1LL * d1 * hikers[1].second;
			LL t0 = 1LL * d0 * hikers[0].second;

			//cout << d1 << " " << d0 << "\n";

			if (t1 <= t0) {
				printf("Case #%d: %d\n", tc, 1);
			} else {
				printf("Case #%d: %d\n", tc, 0);
			}
		}
	}

	tme();
	return 0;
}