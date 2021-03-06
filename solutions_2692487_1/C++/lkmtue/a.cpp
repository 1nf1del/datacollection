//Written by technolt~h
 
#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
 
#define REP(i,n) for(ll i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(ll i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(ll i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
 
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <ll, ll> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 111

int n,a[maxn];
int res;

void att(int x,int ab,int op) {
	if(a[n]<=ab) {
		res=min(res,op);
		return;
	}
	
	int cnt=0;
	FOR(i,1,n) if(a[i]>ab) cnt++;
	res=min(res,op+cnt);
	
	bool found=false;
	FOR(i,1,n) if(x>a[i] && a[i]>ab) x+=a[i],found=true;
	
	if(found) att(x,x-1,op);
	else if(x>1) att(x*2-1,x-1,op+1);
}

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int ntest;
	cin >> ntest;
	FOR(test,1,ntest) {
		int start;
		cin >> start >> n;
		FOR(i,1,n) cin >> a[i];
		sort(a+1,a+n+1);
		res=1000111000;
		att(start,-1,0);
		cout << "Case #" << test << ": " <<res << endl;
		cerr << test << endl;
	}
}
