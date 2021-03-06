// gcc version 4.8.1 20130328 (prerelease) (GCC) at http://www.drangon.org/mingw/
// with -std=c++11

#include <iostream>
#include <sstream>
#include <iomanip>

#include <iterator>

#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

#include <string>

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#include <tuple>
#include <initializer_list>

#include <cmath>

// Boost library can be retrieved from http://www.boost.org/
// 1.52 is used

#pragma GCC diagnostic ignored "-Wconversion"
#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>
#pragma GCC diagnostic warning "-Wconversion"

typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned char UC;

#define RNG(v) (v).begin(), (v).end()
#define REP(v, e) for(UI v = 0U; v < e; ++v)
#define REP_(v, s, e) for(UI v = s; v < e; ++v)
#define REPV(v, e) for(v = 0; v < e; ++v)
#define REPV_(v, s, e) for(v = s; v < e; ++v)

using namespace std;

template<class Integer>
inline boost::iterator_range< boost::range_detail::integer_iterator<Integer> >
IR(Integer first, Integer  last)
{ return boost::irange(first, last); }

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		UI E, R, N; cin >> E >> R >> N;
		vector<UI> v(N); for(auto &i : v) { cin >> i; }
		vector<vector<UI>> t(N, vector<UI>(E+1, 0));
		REP(i, t[N-1].size()) {
			t[N-1][i] = i * v[N-1];
		}
		REP(j_, N-1) {
			UI j = N-2-j_;
			REP(i, t[j].size()) {
				UI temp = 0;
				REP(k, i+1) {
					UI kk = i-k+R;
					if(kk > E) kk = E;
					temp = max(temp, k * v[j] + t[j+1][kk]);
				}
				t[j][i] = temp;
			}
		}
		cout << "Case #" << casenum+1 << ": " << t[0][E] << endl;
	}

	return 0;
}
