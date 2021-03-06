#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <memory>
#include <complex>
using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

#define FOR(i,a,b)	for(int i=(a);i<(int)(b);++i)
#define FORe(i,a,b)	for(int i=(a);i<=(int)(b);++i)
#define REP(i,b)	FOR(i,0,b)
#define REP1(i,b)	FORe(i,1,b)
#define ALL(c)		(c).begin(),(c).end()
#define LET(v,x)	typeof(x) v = x
#define FROMTO(it,b,e)	for(LET(it,(b));it!=(e);++it)
#define FOREACH(it,c)	FROMTO(it,(c).begin(),(c).end())

ll gcd(ll a, ll b){
	if (a && b) for(ll x; b; b = x){
		x = a % b;
		a = b;
	}
	return a;
}
ll gcd(ll a[], int n){
	return n > 0 ? accumulate(a + 1, a + n, a[0], (ll(*)(ll,ll))gcd) : 0LL;
}

ll lcm(ll a, ll b){
	return (a && b) ? a / gcd(a, b) * b : 0LL;
}
ll lcm(ll a[], int n){
	return n > 0 ? accumulate(a + 1, a + n, a[0], (ll(*)(ll,ll))lcm) : 0LL;
}

#define SCAN(p,f)	scanf("%" #f " ",p)
#define GET(t,x,f)	t x;SCAN(&x,f)
#define GETi(x)		GET(int,x,d)
#define GETl(x)		GET(ll,x,lld)
#define GETc(x)		GET(char,x,c)
#define GETf(x)		GET(float,x,f)
#define GETd(x)		GET(double,x,lf)

int a[1010];
int b[1010];
int c[1010];

int earn(int p, int now){
	return ((c[p] < 1) && (a[p] <= now)) + ((c[p] < 2) && (b[p] <= now));
}

int func(int N, int cnt, int star){
	if (star == N * 2){
		return cnt;
	}
	int ret = 10000000;
	REP(i,N){
		int x = earn(i, star);
		if(!x) continue;
		c[i] += x;
		ret = min(ret, func(N, cnt + 1, star + x));
		c[i] -= x;
	}
	return ret;
}

int main(){
	GETi(TTT);
	REP1(ttt, TTT){
		GETi(N);
		REP(i,N){
			GETi(A);
			a[i] = A;
			GETi(B);
			b[i] = B;
			c[i] = 0;
		}
		int ret = func(N, 0, 0);
		if(ret >= 10000000){
			printf("Case #%d: Too Bad\n", ttt);
		}else{
			printf("Case #%d: %d\n", ttt, ret);
		}
	}
	return 0;
}
