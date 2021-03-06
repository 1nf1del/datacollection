#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int m3[12], m5[12], m7[12];

ll eval(int num, ll b) {
	ll v = 0;
	for(int i = 15; i >= 0; i--)
		v = v * b + !!(num & (1 << i));
	return v;
}

struct no {
	int id;
	int dv[11];
	no(int i) : id(i) {
		for(int v = 2; v <= 10; v++) {
			if(v & 1) dv[v] = 2;
			else if(m3[v] == 0) dv[v] = 3;
			else if(m5[v] == 0) dv[v] = 5;
			else dv[v] = 7;
			if(eval(id, v) % dv[v]) printf("(%d)%lld %% %d != 0\n", v, eval(id, v), dv[v]);
			assert((eval(id, v) % dv[v]) == 0);
		}
	}
};
vector<no> s;

void solve(int i, int num, int ct) {
	if(i == 16) {
		if(ct & 1) return;
		for(int v = 2; v <= 10; v += 2)
			if(m3[v] && m5[v] && m7[v])
				return;
		s.pb(no(num));
		if(s.size() == 50) {
			for(no &x : s) {
				printf("%s", bitset<16>(x.id).to_string().c_str());
				for(int v = 2; v <= 10; v++)
					printf(" %d", x.dv[v]);
				putchar('\n');
			}
			exit(0);
		}
		return;
	}
	int b3[12], b5[12], b7[12];
	for(int v = 2; v <= 10; v += 2)
		b7[v] = m7[v], m7[v] = (m7[v] * v) % 7;
	for(int v = 2; v <= 10; v += 2)
		b5[v] = m5[v], m5[v] = (m5[v] * v) % 5;
	for(int v = 2; v <= 10; v += 2)
		b3[v] = m3[v], m3[v] = (m3[v] * v) % 3;

	if(i != 0 && i != 15) solve(i + 1, num << 1, ct);

	for(int v = 2; v <= 10; v += 2)
		m7[v] = (m7[v] + 1) % 7;
	for(int v = 2; v <= 10; v += 2)
		m5[v] = (m5[v] + 1) % 5;
	for(int v = 2; v <= 10; v += 2)
		m3[v] = (m3[v] + 1) % 3;

	solve(i + 1, (num << 1) | 1, ct + 1);

	for(int v = 2; v <= 10; v += 2)
		m7[v] = b7[v];
	for(int v = 2; v <= 10; v += 2)
		m5[v] = b5[v];
	for(int v = 2; v <= 10; v += 2)
		m3[v] = b3[v];
}


int main(int argn, char **args) {
	printf("Case #1:\n");
	solve(0, 0, 0);
}
