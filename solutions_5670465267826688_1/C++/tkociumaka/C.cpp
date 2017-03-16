
#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}


int tab[3][8] = {{2,3,1,0,7,6,4,5},{4,5,6,7,1,0,3,2},{6,7,5,4,2,3,1,0}};

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    LL n, x;
    cin >> n >> x;
    if (x >= 12) x = 8 + x%4;
    string s,t = "";
    cin >> s;
    REP(i, x) t = t+s;
    int val = 0;
    int state = 0;
    for (char c : t) {
        int d = c-'i';
        val = tab[d][val];
        if (state == 0 && val == 2) ++state;
        if (state == 1 && val == 6) ++state;
    }
    cout << ((state == 2 && val == 1)?"YES":"NO") << endl;


}


int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int T;
    cin >> T;
    REP(i,T) solve(i+1);


    return 0;
}
