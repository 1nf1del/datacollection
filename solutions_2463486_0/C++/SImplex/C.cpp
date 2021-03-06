#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//bool is_poly(long long a)
//{
//
//    stringstream ss;
//    ss << a;
//    string s = ss.str();
//    string r = s;
//    reverse(s.begin(), s.end());
//    return s == r;
//}


long long cool[39] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, \
125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, \
1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
//    for (long long i = 1; i <= 10000000; ++i)
//    {
//        if (is_poly(i) && is_poly(i*i))
//            cout << i*i << endl;
//    }
    int T = 0;
    cin >> T;
    for (int step = 1; step <= T; ++step)
    {
        long long A,B;
        cin >> A >> B;
        int ans = 0;
        for (int i = 0; i < 39; ++i)
            if ((cool[i] >= A) && (cool[i] <= B))
                ++ans;
        cout << "Case #" << step << ": " << ans << "\n";
    }


    return 0;
}
