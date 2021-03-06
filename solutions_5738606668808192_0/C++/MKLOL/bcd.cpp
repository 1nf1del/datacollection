#include<bits/stdc++.h>
using namespace std;
int N,M;
vector<int> gv;
int check(long long  x) {
    gv.clear();
    for(int b=2;b<=10;++b) {
        for(int p=2;p<=100;++p) {
            int aux = x;
            long long ax = 1;
            long long sum = 0;
            while(aux) {
                sum += (aux%2) * ax;
                sum %= p;
                ax *= b;
                ax %= p;
                aux = aux / 2;
            }
            if(sum == 0) {
                gv.push_back(p);
                break;
            }

        }
        if(gv.size() != b-1)
            return 0;
    }
    return 1;
}
string make(long long x) {
    string ret = "";
    while(x) {
        string cr = "0";
        if(x%2) cr = "1";
        ret = cr + ret;
        x=x/2;
    }
    return ret;
}
int main() {
    freopen("test4.in","r",stdin);
    freopen("test4.out","w",stdout);
    int T;
    cin >> T;
    cin >> N >> M;
    for (int tt=1;tt<=T;++tt) {
        long long x = 1LL << (N-1);
        printf("Case #%d:\n",tt,N);
        while(M){
            if(x % 2 == 1) {
                if(check(x)) {
                    cout << make(x) << " ";
                    for(auto n : gv)
                        cout << n << " ";
                    cout << endl;
                    --M;
                }
            }
            ++x;
        }
    }
}
