#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

map<long long, int> was;

const int maxn = 1e7;
const int gr = 20;

int q1, q2;
long long q[11000111];

int solve(long long n) {
	was.clear();
	q1 = q2 = 0;

	q[q1++] = n;
	was[n] = 1;

	while (q1 != q2) {
		long long x = q[q2++];
		
//		if (x > maxn) continue;
		if (x == 1) continue;
		int b = was[x];
//		if (b > gr) continue;

		if (was[x - 1] == 0) {
			was[x - 1] = b + 1;
			q[q1++] = x - 1;
		}
		if (x % 10 == 0) continue;

		long long t = 0;
	
		while (x > 0) {
			t = t * 10 + x % 10;
			x /= 10;
		}
		if (was[t] == 0) {
			was[t] = b + 1;
			q[q1++] = t;
		}

	}
	return was[1];
}


int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		long long n;
		cin >> n;
		cout << "Case #" << tt << ": ";

		cout << solve(n) << endl;

	}
	return 0;
}