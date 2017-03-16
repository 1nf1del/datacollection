#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

bool isPali(char *s) {
	int n = strlen(s);
	for (int i = 0; i<n; i++)
		if (s[i] != s[n-1-i])
			return false;
	return true;
}

int64 ileft, iright;

vector<int64> allPali;

char buff[256];
int64 Solve(int64 num) {
	int64 ans = 0;
	for (int i = 0; i < allPali.size(); i++) {
		int64 x = allPali[i];
		if (!(x*x < num)) break;

		sprintf(buff, "%I64d", x*x);
		if (!isPali(buff)) continue;
		ans++;
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int64 i = 1; i<=20000000; i++) {
		sprintf(buff, "%I64d", i);
		if (isPali(buff))
			allPali.push_back(i);
	}
	fprintf(stderr, "!");

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%I64d%I64d", &ileft, &iright);

		int64 ans = Solve(iright + 1) - Solve(ileft);

		printf("Case #%d: %I64d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
