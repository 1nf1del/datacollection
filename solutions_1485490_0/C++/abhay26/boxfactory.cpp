#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#define DN 105
#define LL long long
using namespace std;

int t,n,m;
LL tp[2][DN],cant[2][DN],bst[DN][DN],rez;
//set

inline void back(int i,int j,LL cst) {
    rez=max(rez,cst);
    if(cst<bst[i][j]) return;
    bst[i][j]=cst;
    //if(s.find(make_pair(make_pair(i,j),cst))!=s.end()) return;
    //s.insert(make_pair(make_pair(i,j),cst));
    if(i>n || j>m) return;
    if(tp[0][i]==tp[1][j]) {
        LL cc=min(cant[0][i],cant[1][j]);
        if(cant[0][i]<cant[1][j]) {
            cant[1][j]-=cc;
            back(i+1,j,cst+cc);
            cant[1][j]+=cc;
        }
        else if(cant[0][i]==cant[1][j]) back(i+1,j+1,cst+cc);
        else {
            cant[0][i]-=cc;
            back(i,j+1,cst+cc);
            cant[0][i]+=cc;
        }
    }
    back(i+1,j,cst);
    back(i,j+1,cst);
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
	freopen("out3.txt","w",stdout);
    cin>>t;
    for(int k=1; k<=t; ++k) {
        cin>>n>>m;
        memset(bst,0,sizeof(bst));
       // s.clear();
        //cout<<k<<'\n';
        memset(bst,0,sizeof(bst));
        for(int i=1; i<=n; ++i) cin>>cant[0][i]>>tp[0][i];
        for(int i=1; i<=m; ++i) cin>>cant[1][i]>>tp[1][i];
        rez=0;
        back(1,1,0);
        //for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) rez=max(rez,bst[i][j]);
        cout<<"Case #"<<k<<": "<<rez<<'\n';
        char c;
        //cin>>
    }
    return 0;
}
