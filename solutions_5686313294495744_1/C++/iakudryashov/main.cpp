#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 + 13;

int n;
map<string, int> p[2];
char buf[N];
vector<pt> edges;

inline int getIdx(const string& s, int idx) {
    if (!p[idx].count(s)) {
        int sz = sz(p[idx]);
        p[idx][s] = sz;
    }
    return p[idx][s];
}

inline bool read() {
    if (scanf("%d", &n) != 1) return false;
    edges.clear();
    forn(i, 2) p[i].clear();
    forn(i, n) {
        int a[2];
        forn(j, 2) {
            assert(scanf("%s", buf) == 1);
            a[j] = getIdx(string(buf), j);
        }
        edges.pb(mp(a[0], a[1]));
    }
	return true;
}

vector<int> g[N];
int pr[N];
int used[N], u;

bool khun(int v) {
    if (used[v] == u) return false;
    used[v] = u;

    forn(i, sz(g[v])) {
        int to = g[v][i];
        if (pr[to] == -1 || khun(pr[to])) {
            pr[to] = v;
            return true;
        }
    }

    return false;
}

inline void solve() {
    forn(i, sz(p[0])) g[i].clear();
    forn(i, sz(p[1])) pr[i] = -1;
    forn(i, sz(edges)) {
        int a = edges[i].ft, b = edges[i].sc;
        g[a].pb(b);
    }
    forn(i, sz(p[0])) {
        u++;
        khun(i);
    }
    int ans = sz(p[0]);
    forn(i, sz(p[1])) {
        if (pr[i] == -1) ans++;
    }
    assert(ans <= n);
    cout << n - ans << endl;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

	int testCount;
	cin >> testCount;

	forl(test, testCount) {
#ifdef SU2_PROJ
		cerr << "=== test: " <<  test << ", time: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif
		assert(read());
		printf("Case #%d: ", test);
		solve();
	}
	
#ifdef SU2_PROJ
	cerr << "=== TOTAL TIME: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif

	return 0;
}
