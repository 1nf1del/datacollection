#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int move[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
const double INF = 1e100;
const int MAXN = 128;

double d[MAXN][MAXN];
int H, N, M;
int F[MAXN][MAXN], C[MAXN][MAXN];

struct node {
    double t;
    int x, y;
    node(){}
    node(double _t, int _x, int _y) 
        : t(_t), x(_x), y(_y){}
    bool operator<(const node& rhs) const{
        return t > rhs.t;
    }
};

bool check(int x, int y) 
{
    return x >= 0 && y >= 0 && x < N && y < M;
}

double getCost(node tmp, int x, int y)
{
    if (C[x][y] - F[x][y] < 50)
		return INF;
    if (C[tmp.x][tmp.y] - F[x][y] < 50)
		return INF;
    if (C[x][y] - F[tmp.x][tmp.y] < 50)
		return INF;
    if (C[x][y] - max(F[x][y] * 1.0, H - tmp.t * 10) >= 50)
		return 0;
	else
        return (50 - (C[x][y] - max(F[x][y] * 1.0, H - tmp.t * 10))) / 10.0;
}

void BFS()
{
	int i, j;
	int tx, ty;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			d[i][j] = INF;
    d[0][0] = 0;
    priority_queue<node> q;
    q.push(node(0, 0, 0));
    while (!q.empty())
	{
        node tmp = q.top();
		q.pop();
        for (i = 0; i < 4; ++i)
		{
            tx = tmp.x + move[i][0];
            ty = tmp.y + move[i][1];
            if (!check(tx, ty))
				continue;
            double tempc = getCost(tmp, tx, ty);
            if (tempc == INF)
				continue;
            if (tmp.t + tempc > 1e-7)
			{
                if (H - (tmp.t + tempc) * 10 - F[tmp.x][tmp.y] >= 20)
					tempc += 1.0;
				else
					tempc += 10.0;
            }
            if (d[tx][ty] > tmp.t + tempc)
			{
                d[tx][ty] = tmp.t + tempc;
                q.push(node(tmp.t + tempc, tx, ty));
            }
        }
    }
}

int main()
{
	//freopen("input.txt","r",stdin);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
	int t, cas = 1;
	int i, j;
	scanf ("%d", &t);
	while (t--)
	{
        scanf("%d %d %d", &H, &N, &M);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf ("%d", &C[i][j]);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf ("%d", &F[i][j]);
        BFS();
        printf("Case #%d: %.10lf\n", cas++, d[N-1][M-1]);
    }
    return 0;
}