#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
#include <stdio.h>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin ("INP111.in");

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

int vis[24][24];
int sto[24][24];
int freep;

int nn, mm;

void flood(int a, int b)
{
   if (vis[a][b] == 1)
	   return;
   else
   {
      vis[a][b]=1;
	  freep++;

	  if (a > 0)
	  {
        if (sto[a-1][b] != 1 && vis[a-1][b] !=1 )
			flood(a-1, b);
	  }

	  if (a < nn - 1)
	  {
        if (sto[a+1][b] != 1 && vis[a+1][b] !=1 )
			flood(a+1, b);
	  }

	  if (b > 0)
	  {
        if (sto[a][b-1] != 1 && vis[a][b-1] !=1 )
			flood(a, b-1);
	  }

	  if (b < mm - 1)
	  {
        if (sto[a][b+1] != 1 && vis[a][b+1] !=1 )
			flood(a, b+1);
	  }
   }
}

int main() {

//FILE* pFile;
//pFile = fopen("ou.txt","w");

// string na;
// if (tt == 0)
//  getline(fin,na);

// getline(fin,na);

// istringstream sin(na); 
// string v; 
// while (sin>>v) 
//   names.push_back(v); 

//fprintf(pFile, "Case #%d: ", t+1);
//fprintf(pFile,"%d\n",res);


  long long mo = 1000000007;

  int TT;
  fin >> TT;

  for (int tt=0; tt<TT; tt++)
  {
 
     int n, m, k;
     fin >> n >> m >> k;

     nn = n+2;
	 mm = m+2;

	 long long bes = 2*n + 2*m - 4;
	 for (long long ma = 0; ma < 1 << (n*m); ma++ )
	 {
	    memset(vis, 0, sizeof(vis));
	    memset(sto, 0, sizeof(sto));
        freep = 0;
		long long numsto = 0;
        for (int i=0; i<n; i++)
		{
           for (int j=0; j<m; j++)
		   {
              if ( (ma & (1 << (i*n + m))) > 0)
			  {
                   sto[i+1][j+1] = 1;
				   numsto++;
			  }
		   }
		}

		if (numsto > bes)
			continue;

        flood(0,0);
		int notvis = (n+2)*(m+2) - freep;
		if (notvis >= k)
			bes = min(bes, numsto);
	 }

     fout << "Case #" << tt+1 << ": " << bes-4 << endl;

    

	 //fout.precision(14);
	 //fout << "Case #" << tt+1 << ": " << dis << endl;
	
  }

   return 0;
}

