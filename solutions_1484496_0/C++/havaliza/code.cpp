#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
using namespace std;

#define double long double
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << (x) << endl;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define point complex<double>
//#define X real()
//#define Y imag()
#define X first
#define Y second
#define EPS 1e-12
//#define endl "\n"
#define pdd pair<double, double>
bool gt(double a, double b) { return a > b+EPS; }

const int MAXN = 20;

int n;
int a[MAXN];
map<int, int> mp;

void print(int mask) {
	bool sp = false;
	FOR(i, 0, n) if (mask>>i&1) {
		if (sp) cout << " "; else sp = true;
		cout << a[i];
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	FOR(l, 1, t+1) {
		cin >> n;
		FOR(i, 0, n) cin >> a[i];
		cout << "Case #" << l << ":" << endl;
		mp.clear();
		bool done = false;
		FOR(mask, 0, 1<<n) {
			int sum = 0;
			FOR(i, 0, n) if (mask>>i&1) sum += a[i];
			if (mp.count(sum)) {
				print(mp[sum]);
				print(mask);
				done = true;
				break;
			} else mp[sum] = mask;
		}
		if (!done) cout << "Impossible" << endl;
	}
	return 0;
}

