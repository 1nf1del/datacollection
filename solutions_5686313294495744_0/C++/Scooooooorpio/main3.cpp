#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QMap>
#include <QSet>
#include <QList>
#include <QString>

#include <iostream>
#include <string>
#include <QDebug>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 1100;
const int INF = 0x3f3f3f3f;

struct Node
{
	int to;//终点
	int cap; //容量
	int rev;  //反向边
};

vector<Node> v[N];
bool used[N];
void clearNode() {
	for (int i = 0; i < N; i++) {
		v[i].clear();
	}
}
void addNode(int from, int to, int cap)  //重边情况不影响
{
	Node node;
	node.to = to;
	node.cap = cap;
	node.rev = v[to].size();
	v[from].push_back( node);


	node.to = from;
	node.cap = 0;
	node.rev = v[from].size() - 1;
	v[to].push_back(node);
}

int dfs(int s, int t, int f)
{
	if (s == t)
		return f;
	used[s] = true;
	for (int i = 0; i<v[s].size(); i++)
	{
		Node &tmp = v[s][i];  //注意
		if (used[tmp.to] == false && tmp.cap>0)
		{
			int d = dfs(tmp.to, t, min(f, tmp.cap));
			if (d>0) {
				tmp.cap -= d;
				v[tmp.to][tmp.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int maxFlow(int s, int t)
{
	int flow = 0;
	for (;;){
		memset(used, false, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0)
			return flow;
		flow += f;
	}
}
#if 1
void prework() {

}


void work(int order) {
	clearNode();
	int n;
	cin >> n;
	char s[100];
	QMap<QString, int> left, right;
	int leftSize, rightSize;
	QString s1[1100], s2[1100];

	for (int i = 0; i < n; i++) {
		cin.getline(s, 100);
		cin >> s;
		s1[i] = s;
		cin >> s;
		s2[i] = s;
		qDebug() << s1[i] << s2[i]; 
		left[s1[i]] = 0;
		right[s2[i]] = 0;
	}
	leftSize = left.size();
	rightSize = right.size();

	int re = 0;
	for (int flag = 0; flag < (1 << n); flag++) {
		left.clear();
		right.clear();
		int count = 0;
		for (int i = 0; i < n; i++) {
			if ((flag & (1 << i)) == 0) continue;
			left[s1[i]] = 0;
			right[s2[i]] = 0;
			count++;
		}
		if (left.size() != leftSize) continue;
		if (right.size() != rightSize) continue;

		if (n - count > re) re = n - count;
	}
	qDebug() << re;
	cout << re;
}
	int main(int argc, char *argv[])
	{
		QCoreApplication a(argc, argv);

		if (freopen("..\\temp\\output.txt", "w", stdout) == NULL)
			fprintf(stderr, "error redirecting stdout\n");
		if (freopen("..\\temp\\input.txt", "r", stdin) == NULL)
			fprintf(stderr, "error redirecting stdin\n");
		int t;
		cin >> t;
		prework();
		for (int i = 0; i<t; i++) {

			qDebug() << "case " << i + 1;
			cout << "Case #" << i + 1 << ": ";

			work(i + 1);
			cout << endl;
		}
		qDebug() << "end!";
		return 0;
		return a.exec();
	}
#endif
	 