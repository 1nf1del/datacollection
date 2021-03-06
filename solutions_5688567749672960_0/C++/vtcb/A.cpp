#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define fe(a, b, c) for(int a = b, __ = c; a <= __; a++)

#define rp(a, b) fr(a, 0, b)

#define iter(c) __typeof((c).begin())
#define tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define iz(a) if(a == 0) { break; }

#define FASTIO ios_base::sync_with_stdio(0);

#define F first
#define S second

#define clr(a, b) memset(a, b, sizeof(a))

#define mp make_pair
#define pb push_back

#define sd(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define slf(x) scanf("%lf", &x)
#define sii(x) scanf("%d%d", &x.F, &x.S)
#define sc(x) scanf(" %c", &x)
#define ss(x) scanf(" %s", x)
#define sn(x) scanf(" %[^\n]", x)

#define sd1(a) scanf("%d", &a)
#define sd2(a,b) scanf("%d %d", &a, &b)
#define sd3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sd4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define dbg(x) cout << x << endl;
#define db2(x) cout << #x << " = " << x << endl;
#define _ << ", " <<
#define line(x) { fr(i, 0, x) putchar('-'); puts(""); }
#define hello dbg("hello");

template <class T1, class T2>
	ostream& operator<< (ostream& c, pair<T1, T2> p) { return c << "(" << p.F << ", " << p.S << ")"; }

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
template <class T> inline T sqr(const T& x) { return x * x; }

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const double eps = 1e-7;

int n;

ll reverse(ll n)
{
	string x = tostr(n);
	reverse(x.begin(), x.end());
	return atoi(x.c_str());
}

int main()
{
	int T;
	sd(T);
	
	fe(cas, 1, T)
	{
		ll n;
		sll(n);
		ll ans = 0;
		
		queue<ll> q;
		queue<ll> a;
		set<ll> s;
		
		q.push(1);
		a.push(1);
		s.insert(1);
		
		while(!q.empty())
		{
			ll cur = q.front(); q.pop();
			ll cua = a.front(); a.pop();
			if(cur == n)
			{
				ans = cua;
				break;
			}
			
			ll nxt = cur + 1;
			
			if(s.find(nxt) == s.end() && )
			{
				s.insert(nxt);
				q.push(nxt);
				a.push(cua + 1);
			}
			
			nxt = reverse(cur);
			if(s.find(nxt) == s.end())
			{
				s.insert(nxt);
				q.push(nxt);
				a.push(cua + 1);
			}
		}
		
		printf("Case #%d: %lld\n", cas, ans);
	}
}

