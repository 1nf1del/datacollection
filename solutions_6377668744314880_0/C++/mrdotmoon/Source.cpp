#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#include <iostream>
#include <cmath>
using namespace std;

/*
PointSet[]������ĵ㼯
ch[]�������͹���ϵĵ㼯��������ʱ�뷽������
n��PointSet�еĵ����Ŀ
len�������͹���ϵĵ�ĸ���
*/

struct Point
{
    __int64 x, y;
};

//С��0,˵������p0p1�ļ��Ǵ���p0p2�ļ���
__int64 multiply(Point p1, Point p2, Point p0)
{
    return((p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y));
}

double dis(Point p1, Point p2)
{
    return(sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)));
}


void Graham_scan(Point PointSet[], Point ch[], int n, int &len)
{
    int i, j, k = 0, top = 2;
    Point tmp;

    //�ҵ�������ƫ����Ǹ���
    for (i = 1; i < n; i++)
        if ((PointSet[i].y < PointSet[k].y) || ((PointSet[i].y == PointSet[k].y) && (PointSet[i].x < PointSet[k].x)))
            k = i;
    //�������ָ��ΪPointSet[0]
    tmp = PointSet[0];
    PointSet[0] = PointSet[k];
    PointSet[k] = tmp;

    //�����Ǵ�С����,����ƫ�̽�������
    for (i = 1; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if ((multiply(PointSet[j], PointSet[k], PointSet[0])>0)
                || ((multiply(PointSet[j], PointSet[k], PointSet[0]) == 0)
                && (dis(PointSet[0], PointSet[j]) < dis(PointSet[0], PointSet[k]))))
                k = j;//k���漫����С���Ǹ���,������ͬ����ԭ�����
        tmp = PointSet[i];
        PointSet[i] = PointSet[k];
        PointSet[k] = tmp;
    }
    //������������ջ
    ch[0] = PointSet[0];
    ch[1] = PointSet[1];
    ch[2] = PointSet[2];
    //�ж����������е�Ĺ�ϵ
    for (i = 3; i < n; i++)
    {
        //����������ת�Ĺ�ϵ,ջ��Ԫ�س�ջ
        while (multiply(PointSet[i], ch[top], ch[top - 1]) >= 0) top--;
        //��ǰ����ջ�����е����������ϵ,�����ջ.
        ch[++top] = PointSet[i];
    }
    len = top + 1;
}

bool isPointOnSegment(Point p, Point p1, Point p2)
{
    //����Ƿ�Ϊ0���ж��Ƿ���ͬһֱ����
    if ((p1.x - p.x)*(p2.y - p.y) - (p2.x - p.x)*(p1.y - p.y) != 0)
    {
        return false;
    }
    //�ж��Ƿ����߶���
    if ((p.x > p1.x && p.x > p2.x) || (p.x < p1.x && p.x < p2.x))
    {
        return false;
    }
    if ((p.y > p1.y && p.y > p2.y) || (p.y < p1.y && p.y < p2.y))
    {
        return false;
    }
    return true;
}

const int maxN = 20;
Point PointSet[maxN];
int n;


int slove(int cur)
{
    int res = n;
    for (int i = 0; i <= ((1 << n) - 1); i++)
    {
        if ((1 << cur) & i)
        {
            Point temp[maxN];
            Point ch[maxN];
            int count = 0;
            int len = 0;
            for (int j = 0; j < n; j++)
            {
                if ((1 << j) & i)
                {
                    temp[count++] = PointSet[j];
                }
            }

            if (count > 3)
                Graham_scan(temp, ch, count, len);
            else
            {
                res = min(res, n - count);
                continue;
            }

            bool valid = false;
            for (int k = 0; k < len; k++)
            {
                if (isPointOnSegment(PointSet[cur], ch[k], ch[(k + 1) % len])
                    || (ch[k].x == PointSet[cur].x && ch[k].y == PointSet[cur].y))
                {
                    valid = true;
                    break;
                }
            }

            if (valid) res = min(res, n - count);
        }
    }
    return res;
}

void _main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        __int64 x, y;
        scanf("%lld%lld", &x, &y);
        PointSet[i].x = x;
        PointSet[i].y = y;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", slove(i));
    }
}


int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++)
    {
        printf("Case #%d:\n", cases);
        _main();
    }
}