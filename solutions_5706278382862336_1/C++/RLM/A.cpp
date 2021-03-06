#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

ll mcd(ll a, ll b) { return a ? mcd(b%a, a) : b; }

void simplify(ll &P, ll &Q) {
  ll d = mcd(P, Q);
  P /= d;
  Q /= d;
}

int main() {
  int T; cin >> T;
  char x;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    ll P, Q; cin >> P >> x >> Q;
    simplify(P, Q);
    if (__builtin_popcount(Q) != 1) cout << "impossible" << endl;
    else {
      int q = 0;
      while (Q > P) {
        Q /= 2;
        ++q;
      }
      cout << q << endl;
    }
  }
}
