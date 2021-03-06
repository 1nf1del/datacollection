#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <utility>
#include <ctime>
#include <string>
#include <sstream>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))

// template end

struct Outfit
{
    int jn, pn, sn;
};

int J, P, S, K;
int sets;
vector<Outfit> g_outfits;

vector<Outfit> getOutfits(int mask)
{
    vector<Outfit> outfits;
    int bit = 0;
    for (int jn = 1; jn <= J; ++jn)
    {
        for (int pn = 1; pn <= P; ++pn)
        {
            for (int sn = 1; sn <= S; ++sn)
            {
                if ((mask >> bit) & 1)
                {
                    outfits.push_back(Outfit{ jn, pn, sn });
                }
                ++bit;
            }
        }
    }
    return outfits;
}

vector<Outfit> getOutfits()
{
    vector<Outfit> outfits;
    for (int jn = 1; jn <= J; ++jn)
    {
        for (int pn = 1; pn <= P; ++pn)
        {
            for (int sn = 1; sn <= S; ++sn)
            {
                outfits.push_back(Outfit{ jn, pn, sn });
            }
        }
    }
    return outfits;
}

const int MAX_S = 4;
int appears[MAX_S][MAX_S][MAX_S];

bool check(int mask)
{
    ZERO(appears);

    for (int i = 0; i < sets; ++i)
    {
        if (!((mask >> i) & 1))
        {
            continue;
        }

        Outfit &o = g_outfits[i];

        appears[o.jn][o.pn][0]++;
        appears[o.jn][0][o.sn]++;
        appears[0][o.pn][o.sn]++;
    }

    for (int i = 0; i < MAX_S; ++i)
    {
        for (int j = 0; j < MAX_S; ++j)
        {
            for (int k = 0; k < MAX_S; ++k)
            {
                if (appears[i][j][k] > K)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int ones(int mask)
{
    int ans = 0;
    while (mask > 0)
    {
        if (mask & 1)
        {
            ++ans;
        }
        mask >>= 1;
    }
    return ans;
}

vector<vector<Outfit>> precalc = { { { 1, 1, 2 },
{ 1, 2, 1 },
{ 1, 3, 3 },
{ 2, 1, 1 },
{ 2, 2, 3 },
{ 2, 3, 2 },
{ 3, 1, 3 },
{ 3, 2, 2 },
{ 3, 3, 1 } }, { { 1, 1, 1 },
{ 1, 1, 3 },
{ 1, 2, 1 },
{ 1, 2, 2 },
{ 1, 3, 2 },
{ 1, 3, 3 },
{ 2, 1, 1 },
{ 2, 1, 2 },
{ 2, 2, 2 },
{ 2, 2, 3 },
{ 2, 3, 1 },
{ 2, 3, 3 },
{ 3, 1, 2 },
{ 3, 1, 3 },
{ 3, 2, 1 },
{ 3, 2, 3 },
{ 3, 3, 1 },
{ 3, 3, 2 } }, { { 1, 1, 1 },
{ 1, 1, 2 },
{ 1, 1, 3 },
{ 1, 2, 1 },
{ 1, 2, 2 },
{ 1, 2, 3 },
{ 1, 3, 1 },
{ 1, 3, 2 },
{ 1, 3, 3 },
{ 2, 1, 1 },
{ 2, 1, 2 },
{ 2, 1, 3 },
{ 2, 2, 1 },
{ 2, 2, 2 },
{ 2, 2, 3 },
{ 2, 3, 1 },
{ 2, 3, 2 },
{ 2, 3, 3 },
{ 3, 1, 1 },
{ 3, 1, 2 },
{ 3, 1, 3 },
{ 3, 2, 1 },
{ 3, 2, 2 },
{ 3, 2, 3 },
{ 3, 3, 1 },
{ 3, 3, 2 },
{ 3, 3, 3 } } };

void solve()
{
    cin >> J >> P >> S >> K;

    if (J == 3 && P == 3 && S == 3)
    {
        int key = min(2, K - 1);
        cout << precalc[key].size() << endl;
        for (auto& o : precalc[key])
        {
            cout << o.jn << " " << o.pn << " " << o.sn << endl;
        }
        return;
    }

    sets = J * P * S;
    int subsets = 1 << sets;

    int bestones = 0;
    int bestmask = 0;
    g_outfits = getOutfits();

    for (int mask = 0; mask < subsets; ++mask)
    {
        if (!check(mask))
        {
            continue;
        }

        int maskones = ones(mask);
        if (maskones > bestones)
        {
            bestones = maskones;
            bestmask = mask;
        }
    }

    vector<Outfit> outfits = getOutfits(bestmask);
    cout << bestones << endl;
    for (auto& o : outfits)
    {
        cout << o.jn << " " << o.pn << " " << o.sn << endl;
    }
}

int main()
{
#ifdef XXX
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#elif defined CONTEST
    freopen(CONTEST".in", "r", stdin);
    freopen(CONTEST".out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; ++tc)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}