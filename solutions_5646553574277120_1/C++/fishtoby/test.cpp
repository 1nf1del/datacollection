#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main(){
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	int nn,r=1,c,i,j,n,t,ans;
	long long now;
	scanf("%d",&nn);
	while(nn--){
		cin>>c>>n>>t;
		for(i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		ans=i=now=0;
		while(1){
			while(i<n&&now>=a[i]-1){
				now+=c*a[i];
				i++;
			}
			if(now>=t) break;
			now+=(now+1)*c;
			ans++;
		}
		cout<<"Case #"<<r<<": "<< ans <<endl;
		r++;
	}
	return 0;
}
/*
100
1 2 3
1 2
1 4 22
1 4 7 15
1 2 16
1 2
1 4 29
2 7 10 22
1 1 30
1
1 5 19
1 4 7 12 19
1 3 19
4 16 19
1 3 23
5 20 23
1 2 21
8 21
1 4 24
1 3 6 14
1 2 6
5 6
1 1 30
30
1 1 1
1
1 3 18
4 5 14
1 2 15
14 15
1 1 1
1
1 2 14
5 7
1 1 2
1
1 2 11
4 5
1 3 24
7 19 24
1 1 3
3
1 4 16
1 4 9 11
1 1 2
1
1 1 27
2
1 2 23
12 23
1 3 21
5 9 19
1 1 3
3
1 1 20
20
1 2 28
13 17
1 4 13
5 6 12 13
1 2 26
6 26
1 1 2
1
1 3 28
22 25 28
1 1 1
1
1 2 20
3 20
1 3 24
4 6 15
1 2 8
5 6
1 1 26
26
1 1 29
28
1 2 9
2 3
1 3 19
5 6 12
1 1 4
4
1 1 20
17
1 5 5
1 2 3 4 5
1 3 8
2 5 7
1 1 13
2
1 1 7
1
1 4 17
1 9 16 17
1 1 7
5
1 2 2
1 2
1 4 6
1 2 4 5
1 2 23
1 22
1 3 23
21 22 23
1 3 30
13 19 25
1 4 26
20 23 25 26
1 3 7
3 5 7
1 2 21
8 17
1 5 30
1 2 4 8 15
1 1 20
18
1 3 20
3 8 15
1 2 20
15 20
1 3 25
1 2 7
1 5 16
1 2 4 8 16
1 3 27
8 22 25
1 2 27
3 7
1 1 28
2
1 3 6
1 2 5
1 3 27
3 4 9
1 4 14
7 11 12 14
1 3 26
22 25 26
1 4 16
1 2 4 8
1 3 19
2 7 14
1 1 29
18
1 2 18
4 9
1 1 26
5
1 1 20
14
1 3 5
2 4 5
1 1 24
22
1 2 29
7 14
1 2 28
2 4
1 1 7
5
1 2 26
13 22
1 2 17
7 17
1 4 25
1 5 10 19
1 3 20
3 5 13
1 4 26
4 6 12 25
1 3 30
10 17 18
1 3 10
8 9 10
1 2 2
1 2
1 3 29
1 4 8
1 1 2
1
1 1 20
5
1 4 30
4 7 12 28
1 1 4
3
1 2 25
3 8
1 1 28
18
1 2 6
4 6
1 4 26
3 5 10 22
1 3 13
2 5 12
1 1 3
3

*/
