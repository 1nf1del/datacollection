#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>
#include <numeric>
#include <limits.h>
#include <limits>
#include <iterator>
#include <iomanip>
#include <bitset>
#include <assert.h>

using namespace std;

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

typedef long long LL;

ifstream input;
ofstream output;
bool writeToFile = false;

void setSIO(std::string iFilePath, std::string oFilePath) {
    cin.sync_with_stdio(false);
    cout << setprecision(16);
    if (writeToFile) {
        streambuf *i, *o;
        input.open(iFilePath.c_str(), ifstream::in);
        i = input.rdbuf();
        output.open(oFilePath.c_str(), ifstream::out);
        o = output.rdbuf();
        cin.rdbuf(i);
        cout.rdbuf(o);
    }
}

int testIndex = 1;

template <typename T>
void printTest(T result) {
    cout << "Case #" << testIndex << ": " << result << endl;
    testIndex++;
}

void main2();

typedef pair< pair<int, int>, int > ww;

int main(int argc, char** argv) {
    writeToFile = true;
    setSIO("in.txt", "out.txt");
    int T;
    cin >> T;

    REP(t, T) {
        main2();
        assert(cin);
    }
    cout.flush();
    return 0;
}

int A[1005], B[1005];
const int INF = 1 << 29;

void main2() {
    mem0(A);
    mem0(B);
    int N;
    cin >> N;
    REP(i, N) cin >> A[i] >> B[i];
    int a = -1, b = -1, result = 0, stars = 0, minB = 1 << 29;

    while (stars < 2 * N) {
        a = -1, b = -1, minB = -1;

        REP(i, N) {
            if (B[i] <= stars) {
                b = i;
                continue;
            }
            if (A[i] <= stars && B[i] > minB) a = i, minB = B[i];
        }
        if (b != -1) {
            if (A[b] == INF) stars++, B[b] = INF;
            else stars += 2, A[b] = INF, B[b] = INF;
        } else if (a != -1) A[a] = INF, stars++;
        else {
            printTest("Too Bad");
            return;
        }
        result++;
    }

    printTest(result);
}
