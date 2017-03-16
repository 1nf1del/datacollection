// https://pp.vk.me/c540102/v540102394/7cd5/J2NXxBbvBrM.jpg
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <sstream>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
//#include <array>
//#include <unordered_set>
//#include <unordered_map>
#include <cassert>
#include <iomanip>
#define mp make_pair
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define FORA(e,c) for(auto &e:c)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x))
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]))
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FIN freopen("in.txt", "r", stdin);
#define FINOUT freopen("in.txt", "w", stdout);
#define FOUT freopen("out.txt", "w", stdout);
#define y1 ____y1
using namespace std;
typedef const int CI;
typedef long long ll;
typedef unsigned long long ull;
// typedef __float128 ld;
// typedef long double ld;
typedef double ld;
typedef vector<int> VINT;
typedef vector<ld> VLD;
typedef vector<ll> VLL;
typedef vector<vector<int> > VVINT;
typedef set<int> SI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<ll, ll> PLL;
typedef pair<ld, ld> PLD;
typedef pair<ld, ld> ptp;
typedef complex<ld> Cn;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PIII> VPIII;
typedef vector<PLD> VPLD;
typedef set<PII> SII;
#include <array>
template <int n> using AI=array<int, n>; typedef AI<2> AII; typedef AI<3> AI3; typedef AI<4> AI4;
typedef unsigned int uint;
const ld eps=1e-9;
const int oo=0x3F3F3F3F;
const ll ooLL=0x3F3F3F3F3F3F3F3FLL;
const int MOD=1000000007;
template<typename T> T sqr(T x) { return x*x; }
#ifdef EgQrauETGh
template<typename T> void debpr(const T &);
template<typename T1, typename T2> void debpr(const pair<T1, T2> &);
template<typename T1, typename T2> void debpr(const vector<T1, T2> &);
template<typename T1, typename T2> void debpr(const set<T1, T2> &);
template<typename T1, typename T2> void debpr(const multiset<T1, T2> &);
template<typename T1, typename T2> void debpr(const map<T1, T2> &);
template<typename T, size_t n> void debpr(const array<T, n> &);
template<typename T> void prcont(T be, T en, const string &st, const string &fi, const string &mi) { debpr(st); bool ft=0; while (be!=en) { if (ft) debpr(mi); ft=1; debpr(*be); ++be; } debpr(fi); }
template<typename T> void debpr(const T &a) { cerr<<a; }
template<typename T1, typename T2> void debpr(const pair<T1, T2> &p) { debpr("("); debpr(p.first); debpr(", "); debpr(p.second); debpr(")"); }
template<typename T1, typename T2> void debpr(const vector<T1, T2> &a) { prcont(a.begin(), a.end(), "[", "]", ", "); }
template<typename T, size_t n> void debpr(const array<T, n> &a) { prcont(a.begin(), a.end(), "[", "]", ", "); }
template<typename T1, typename T2> void debpr(const set<T1, T2> &a) { prcont(a.begin(), a.end(), "{", "}", ", "); }
template<typename T1, typename T2> void debpr(const multiset<T1, T2> &a) { prcont(a.begin(), a.end(), "{", "}", ", "); }
template<typename T1, typename T2> void debpr(const map<T1, T2> &a) { prcont(a.begin(), a.end(), "{", "}", ", "); }
void debp() {}
template<typename T, typename... U> void debp(T x, U... y) { debpr(x); debpr(' '); debp(y...); }
template<typename... T> void debs(T... x) { debp(x...); debpr('\n'); }
bool asse() { return 1; }
template<typename T, typename... U> bool asse(T x, U... y) { return x && asse(y...); }
template<typename... T> void asss(string t, T... x) { if (!asse(x...)) { cerr<<t<<" ASSERTION FAILED!"<<endl; throw; }}
#define deb(...) debs("LINE "+to_string(__LINE__)+":\t", __VA_ARGS__)
#define ass(...) asss("LINE "+to_string(__LINE__)+":\t", __VA_ARGS__)
ostream& operator<<(ostream &o, __float128 f) { o<<(long double)f; return o; }
__float128 abs(__float128 x) { return x<0?-x:x; }
__float128 log(__float128 x) { return log((long double)(x)); }
__float128 sqrt(__float128 x) { return sqrt((long double)(x)); }
#else
#define deb(...) ;
#define ass(...) ;
#endif
const ld PI=acos(-1.);
ll Round(double x) { return x<0?x-.5:x+.5; }
int main()
{
#ifdef EgQrauETGh
    // FIN;
    ld tm=clock();
    cerr<<"====================================================="<<endl;
#else
    // freopen("list-powers.in", "r", stdin); freopen("list-powers.out", "w", stdout);
#endif
    void run(); run();
#ifdef EgQrauETGh
    cerr<<"====================================================="<<endl;
    cerr<<setprecision(3)<<fixed<<(clock()-tm)/CLOCKS_PER_SEC<<" sec" << endl;
    if (sizeof(ld)!=sizeof(double)) {
        cerr<<"WARNING:    ld is not double!"<<endl;
    }
#endif
    return 0;
}
#define pb push_back
#define X first
#define Y second

// g++ -Wall -Wno-sign-compare -Wno-unused-result -DEgQrauETGh -O3 -std=c++14 -o main main.cpp
// ulimit -s unlimited
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CI N=1<<20;
int nte, d[N], m[N], h[N], nn;
int slv()
{
    // deb("---");
    VINT p, s;
    REP(i, nn) REP(j, h[i])
    {
        p.pb(d[i]);
        s.pb(m[i]+j);
    }
    int n=p.size();
    int rs=n;
    REP(i, n)
    {
        ll t=(360LL-p[i])*s[i];
        ll c=0;
        // deb(">>>", i, t);
        REP(j, n)
        {
            ll e=p[j]+t/s[j];
            // deb(j, e);
            if (e<360) ++c;
            else c+=e/360-1;
        }
        // deb("<<<", i, c);
        if (rs>c) rs=c;
    }
    return rs;
}
void run()
{
    scanf("%d", &nte);
    REP(nt, nte)
    {
        printf("Case #%d: ", nt+1);
        scanf("%d", &nn);
        REP(i, nn) scanf("%d %d %d", &d[i], &h[i], &m[i]);
        printf("%d\n", slv());
    }
}