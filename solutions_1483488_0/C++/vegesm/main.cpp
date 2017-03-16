#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;
char buff[40];

void solve(istream& in, ostream& out)
{
    int a,b;
    int ret=0;
    in>>a>>b;
    set<int> pairs;
    for(int i=a; i<b; i++)
    {
        itoa(i, buff, 10);
        int len=strlen(buff);
        string s(buff);
        s=s+s;
        pairs.clear();
        for(int j=1; j<len; j++)
        {
            //cout<<i<<", "<<j<<": ";
            if(s[j]=='0') {
                //cout<<endl;
                continue; //ne kezd�dj�n 0-val;
            }

            int n=atoi(s.substr(j,len).c_str());
            //cout<<n<<endl;
            if(n>i && n<=b){
                //ret++;
                //cout<<"ret="<<ret<<"; i="<<i<<"; n="<<n<<endl;
                pairs.insert(n);
            }

        }
        ret+=pairs.size();
    }
    out<<ret;
}

int main()
{
    ifstream in("C-small-attempt0.in");
    ofstream out("recycle.out");
    int cases;
    in>>cases;
    for(int i=0;i<cases;i++)
    {
        out<<"Case #"<<(i+1)<<": ";
        solve(in, out);
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
