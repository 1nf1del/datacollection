#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = (int) fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
    v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

#define maxn 10005
#define mod 7340033
#define eps 1e-6

int e, R, n, a, u, v;
int next[maxn];
ll l[maxn], r[maxn];
pair<int, int> P[maxn];
int test;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//    freopen("symmetry.out", "w", stdout);

	cin >> test;

	For(itest, 1, test){

		cin >> e >> R >> n;
		For(i, 1, n){
			cin >> a;
			P[i] = mp(a, i);
		}

		sort(P + 1, P + n + 1);
		ms(next, 0); ms(r, 0); For(i, 0, n + 1) l[i] = e;
		set<int> S;
		set<int>::iterator it;
		next[0] = n + 1;
		S.insert(0); S.insert(n + 1);
		ull res = 0;
		Ford(i, n, 1){
			a = P[i].se;
			it = S.lower_bound(a);
			it--;
			u = (*it); v = next[u];
			r[a] = min((ll)e, l[u] + (a - u) * 1ll * R);
			l[a] = max((ll)0, r[v] - (v - a) * 1ll * R);
//			cout << a << " " << u << " " << v << " " << l[a] << " " << r[a] << endl;
			res += (r[a] - l[a]) * 1ll * P[i].fi;
			next[u] = a;
			next[a] = v;
			S.insert(a);
		}

		cout << "Case #" << itest << ": " << res << endl;
	}

    return 0;
}
