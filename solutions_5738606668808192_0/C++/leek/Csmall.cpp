#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll pow2(ll b, ll p ) {
  if(p== 0) return 1;
  ll hf = pow2(b, p/2);
  ll ret = hf * hf;
  if(p % 2) ret *= b;
  return ret;

}
string toString(int x) {
  string ret = "";
  while( x > 0) {
    if ( x % 2 ) ret += '1';
    else ret += '0';
    x = x /2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}


vector<ll > okay(int x) {
  vector<int> a;
  int i = 0;
  int xx = x;
  while( xx > 0) {
    if(xx%2) a.push_back(i);
    i ++;
    xx /= 2;
  }

  vector<ll > ret;
  for(ll b =2 ;b<=10; b++) {
    ll y = 0;
    for(int j =0; j<a.size(); j++) {
      y += pow2(b, a[j]);
    }
    bool found = false;
    for(ll k = 2; k * k <= y ; k++) {
      if(y % k == 0) {
        ret.push_back(k);
        found = true;
        break;
      }
    }
    if(!found) return ret;
  }
  return ret;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    printf("Case #%d:\n",tc);
    int n,j;
    cin >> n >> j;
    int x = 1 << (n-1);

    x ++;
    while ( j >0 ) {
      if(x%2 ==0) {
        x ++;
        continue;
      }
      vector<ll> r = okay(x);
      if(r.size() == 9) {
        cout << toString(x);
        for(int i =0; i<r.size(); i++) {
          cout << ' ' << r[i];
        }
        cout << endl;
        j --;
      }
      x++;
    }

  }

  return 0;
}