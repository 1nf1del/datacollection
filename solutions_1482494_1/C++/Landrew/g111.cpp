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
ifstream fin ("INP111.txt");

//FILE* pFile;
//int c;
//pFile = fopen("ou.txt","w");
//pFile=fopen ("beads.txt","r");

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

  int TT;
  fin >> TT;

  int n;

  for (int tt=0 ;tt<TT; tt++)
  {
    fin >> n;
	int a, b;
	int done[1003];
	memset(done, 0, sizeof(done));
	//vector < vector <int> > aa;
	vector < vector <int> > bb;
	map <int, int> M;
	for (int i=0; i<n; i++)
	{
       fin >> a >> b;
	   vector <int > t;
	   t.push_back(b);
	   t.push_back(i);
	   bb.push_back(t);
	   M[i]=a;
	}

	//sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	//reverse(aa.begin(), aa.end());

	//int inda = 0;
	int indb = 0;
    int cur  = 0;
	int ntimes = 0;

	bool failed = false;
	while (indb < n && !failed)
	{ 
       if (bb[indb][0] <= cur)
	   {
          if (done[bb[indb][1]] == 0)
            cur += 2;
		  else
		    cur++;
		  done[bb[indb][1]]=1;
		  indb++;
		  ntimes++;
	   }
	   else
	   {
          failed = true;
		  int indat = n-1;
		  bool found = false;
          int indf = 0;
		  while (indat >= 0 && !found)
		  {
             if (done[bb[indat][1]] == 1)
			   indat--;
			 else
			 {
                if (M[bb[indat][1]] <= cur)
				{
                   found = true;
                   indf  = bb[indat][1];
				}
				else
				{
                   indat--;
				}
			 }
		  }

		  if (found)
		  {
             failed = false;
             cur++;
		     done[indf]=1;
		     ntimes++;
		  }
	   }
	}

    if (failed)
        fout << "Case #" << tt+1 << ": Too Bad" << endl;
	else
        fout << "Case #" << tt+1 << ": " << ntimes << endl;
  }

   return 0;
}
