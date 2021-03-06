#include <iostream>
#include <algorithm>
using namespace std;
#define INPUT "C-small-attempt0.in"
#define OUTPUT "output.txt"

typedef unsigned long long ULL;

int C, D, V;
int coin[10];

int solv()
{
		int count = 0;
		int p = 0;
		int c = 0;

		while (p < V) {
				while (coin[c] > p+1) {
						++ count;
						cerr << "use " << p + 1 << endl;
						p += p+1;
				}
				p += coin[c++];
		}
		return count;
}


int main()
{
		int T, nCase = 1;

		freopen("C:\\Users\\Frog\\Downloads\\"INPUT, "r", stdin);
		freopen("C:\\Users\\Frog\\Downloads\\"OUTPUT, "w", stdout);

		cin >> T;
		for (nCase = 1; nCase <= T; nCase ++) {
				cin >> C >> D >> V;
				for (int i=0;i<D;++i) cin >> coin[i];
				sort(coin, coin+D);
				coin[D++] = V+1;
				cout << "Case #" << nCase << ": " << solv() << endl;
		}

		return 0;
}
