#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>

 
using namespace std;



int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
	  clock_t start,end;
	 start = clock();
   int testcasenum;
    cin >> testcasenum;//
	
    for (int t = 1; t <= testcasenum; ++t) {
        printf("Case #%d: ", t);
         int n;
		 string str;
        cin >> str >> n;
		int count=0;
		int maxval=0;
		vector<int> ints(str.size(),0);
		int loc=-1;
		for(int i=0;i<str.size();i++){
			if(str[i]!='a' && str[i]!='e' && str[i]!='i'
				&& str[i]!='o' && str[i]!='u'){
					
					count++;
					if(count>n){ints[i]=n;}else{ints[i]=count;}
					if(maxval<count){
						maxval=count;
						loc=i;
					}
			
			}else{count=0;}
		}//�I���

		int countchar=0;
		int answer=0;

		for(int i=0;i<str.size();i++){
			if(ints[i]==n){
					answer+=(countchar+2-n)*(str.size()-i);
					countchar=n-1;
					//cout<<"i="<<i<<"answer="<<answer<<endl;
			}
			else if(ints[i]<n){
				countchar++;
			}
		}

		
		//cout<<endl;
		//cout<<"�ő�A��"<<maxval<<"count"<<count<<endl;
		cout<<answer<<endl;
       // cout<< str<<" cons="<<consec;
        
    }
     end = clock();
 // printf("%.2f�b������܂���\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
