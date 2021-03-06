#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set> // C++11
#include <unordered_map> // C++11
#include <tuple>         // C++11
#include <bitset>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
 
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }
 
#define N (1024)
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin >> TC;
  FOR(tc, 0, TC){
	int n;
	cin >> n;
	n++;
	vi s(n);
	FOR(i,0,n){
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	int req = 0;
	int standing = 0;
	FOR(i,0,n){
		if(standing >= i){
			standing += s[i];
		}
		else{
			req += (i - standing);
			standing += (i - standing) + s[i];
		}
	}
	cout << "Case #" << tc+1 << ": " << req << endl;
  }
}
