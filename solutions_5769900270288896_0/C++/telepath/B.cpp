#if 01
/*******************************************************************************
* Author       : Aman Taneja
* email        : aman (dot) taneja (dot) 2008 (at) gmail (dot) com
* copyright    : 2014 - 2015
* date         : 01 - 05 - 2015
* 
* file name    : A.cpp
* version      : 1.0
*
* TERMS OF USE - Write a mail to the author before copying or reusing the content of this file 
* seeking our permission for the same.
* Copying/reuse of the below code without the permission of the author is prohibited and illegal.
*
* All rights reserved by Aman Taneja.
******************************************************************************/

/*******************************************************************************
* some pointers on the logic/idea - 
*
* .............
*******************************************************************************/

#pragma once
#ifndef _QL_PRECOMPILATION_BARE_MINIMUM_HPP_
#define _QL_PRECOMPILATION_BARE_MINIMUM_HPP_

// Include file for std::cout, std::cin
#include<iostream>
#include <fstream>

// for itoa - does not work on some compilers(despite including cstdlib)
#include <cstdlib>
// for getch()
#include<stdio.h>

// For clock time and time duration stats
#include <time.h>

#include <map>
#include <vector>
#include <string>
#include <cstring>

#include <set>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <stack>
#include <limits.h>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <complex>
#include <valarray>
#include <iterator>

using namespace std;

namespace QoE_Library{

	namespace QL_Bare_Minimum{

		// constants
		// -----------------------------------------
		const double PI = 3.141592653589793238460;
		// const values
		const long double pi=10000*acos(-1.0L);
		const long double E= 2.7182818284590452353;
		const long double eps=1e-10;


		// 2 D array movement
		// -----------------------------------------
		const int DX4[]={0,1,0,-1};
		const int DY4[]={1,0,-1,0};
		const int DX8[]={-1,-1,-1,0,0,1,1,1};
		const int DY8[]={-1,0,1,-1,1,-1,0,1};

#define SETZERO(a) memset(a,0,sizeof(a))
#define SETVAL(a,val) memset(a,val,sizeof(a))
#define SETDP(a) memset(a,-1,sizeof(a))

		// check whether indices in range of an array/matrix or values
#define in_bounds(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)
#define in_range(x, lo, hi) (x <= hi && x >= lo )

		// get min of 3 values
#define min3(a,b,c)	(a<min(b,c))?a:min(b,c)
#define max3(a,b,c)	((a>max(b,c))?a:max(b,c))


		// convert char into index
#define CHAR_TO_INDEX(c,startC) ((int)c - (int)startC)

		// Array size
#define SZ_ARR(A) sizeof(A)/sizeof(A[0])
		// STL MACROS -
#define SZ(C) C.size()

#define ALL(x) (x).begin(), (x).end()

		//pair 
#define MKP(i,j) make_pair(i,j)
		// Map
#define M_Ins(_m_,i,j) _m_.insert(make_pair(i,j))

		// vector
#define PB(A,B) A.push_back(B);

		// STL sort()
#define SORT(A) sort( A.begin(),A.end() )


		// For loop
#define FOR(i, first, last, increment) for (int i = (first); i < (last); i = i + (increment))
#define QL_FOR FOR

#define DEBUGGING 1

		// Default For loop with variable name "i", first = 0, increment = 1
#define FOR_DEF(i, last) QL_FOR(i, 0, last, 1)
#define QL_FOR_DEF FOR_DEF


		// Dont care about the looping variable name
		// TODO : Need to solve the problem of generating a unique temp loop var, for now __i__ suffices
#define REPEAT(N) for (int __i__ = 0; __i__ < (N); ++__i__)



		// Reverse For loop
#define R_FOR(i, first, last, increment) for (int i = ((first) - 1); i >= (last); i = i - (increment))
#define QL_R_FOR R_FOR



		// Default For loop with variable name "i", first = 0, increment = 1
#define R_FOR_DEF(i, first) QL_R_FOR(i, first, 0, 1)
#define QL_R_FOR_DEF R_FOR_DEF

#define FOR_STL(i,stl) for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define EXISTS(c,e) ((c).find(e)!=(c).end())

		// For loop for map
#define QL_M_FOR(m,T1,T2,it) for(map<T1,T2>::iterator it=m.begin();it!=m.end();++it)
#define QL_M_R_FOR(m,T1,T2,rit) for(map<T1,T2>::reverse_iterator rit=m.rbegin();rit!=m.rend();++rit)


#define QL_M_FOR(m,it) QL_M_FOR(m,int,int,it)   // for(map<int,int>::iterator it=m.begin();it!=m.end();++it)
#define QL_M_R_FOR(m,rit) QL_M_R_FOR(m,int,int,it)   //for(map<int,int>::reverse_iterator rit=m.rbegin();rit!=m.rend();++rit)


		typedef unsigned long long int ulli_t;
		typedef ulli_t ULLI;
		typedef vector<ulli_t> uivector_t;
		typedef uivector_t::iterator uivector_it_t;
		typedef uivector_t::const_iterator uivector_cit_t;


		typedef long long int lli_t;
		typedef lli_t LLI;
		typedef vector<lli_t> ivector_t;
		typedef ivector_t::iterator ivector_it_t;
		typedef ivector_t::const_iterator ivector_cit_t;


		// pair
		typedef pair<int,int> p_ii_t;
		typedef p_ii_t P_II;
		typedef pair<LLI,LLI> p_llilli_t;
		typedef p_llilli_t P_LLILLI;

		// vector
		typedef vector<int> v_i_t;
		typedef v_i_t V_I;
		typedef vector<LLI> v_lli_t;
		typedef v_lli_t V_LLI;
		typedef vector<ULLI> v_ulli_t;
		typedef v_ulli_t V_ULLI;

		typedef vector<p_ii_t> v_p_ii_t;
		typedef v_p_ii_t V_P_II;

		typedef vector<v_i_t> vv_i_t;
		typedef vv_i_t VV_I;
		typedef vector<v_p_ii_t> vv_p_ii_t;
		typedef vv_p_ii_t VV_P_II;

		typedef vector<string> v_s_t;
		typedef v_s_t V_S;

		//map
		typedef map<int,int> M_II;
		typedef map<int,int>::iterator M_II_IT;

		//queue
		typedef queue<int> q_i_t;
		typedef q_i_t Q_I;

		typedef long double ld_t;
		typedef ld_t LD;


		/*	-------	BEWARE -	macros can't be overloaded i.e. both the 'read's below	
		can't have the same name	---------- */
#define read1(n) cin >> n;
#define read2(m, n) cin >> m >> n;
#define read3(m, n, o) cin >> m >> n >> o;
		// #define readArr(n, size) QL_FOR_DEF(i, size) { cin >> n[i]; } 
#define readArr1D(n, size)	QL_FOR_DEF(i, size)	\
		{					\
		cin >> n[i];	\
		} 

#define write1(n) cout << n;
#define write2(m, n) cout << m << n;
#define write3(m, n, o) cout << m << n << o;
#define writeArr1D(n, size)	QL_FOR_DEF(i, size)	\
		{					\
		cout << n[i];	\
		} 

#define DBG(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DBG2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DBG3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#define DBG4(a, b, c, d)    cout<<__LINE__<<" :: "<<#a<< ": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;


		/* stoi,itos and atoi & itoa functions parse only a single int to string and 
		vice-a-versa. The below function can do it for any number of data in the string.
		As shown below.

		A more convenient tool to use is - sscanf().
		sscanf(s.c_str(),"%d%c%d",&a,&c,&b);
		*/
		template<typename T1> inline T1 to_type(string s){
			T1 a;
			istringstream sin(s);
			sin>>a;
			// for 3 data values to be parsed from the string do -
			//sin>>a>>b>>c;
			return a;
		}
		template<typename T1> inline string to_str(T1 a){
			ostringstream sout;
			string s;
			sout>>a;
			// for 3 data values to be converted to string do -
			//sout>>a>>b>>c;
			return sout.str();
		}

		inline void inpS(char *a){
			scanf("%s", a);
		}

		inline int inpLLI(LLI& lld){
			return scanf("%lld", &lld);
		}
		inline int inpULLI(ULLI& ulli){
			return scanf("%llu", &ulli);
		}

		// Fast reading Integer from stdin.
		inline int inpI(/*int &n*/) {
			int n = 0;
			int ch = getchar();
			// int ch = getchar_unlocked();
			int sign = 1;
			while(ch < '0' || ch > '9') {
				if (ch == '-') sign = -1; 
				ch = getchar();
				// ch = getchar_unlocked();
			}
			while(ch >= '0' && ch <= '9')
				n = (n<<3) + (n<<1) + ch - '0', ch = getchar();
			// n = (n<<3) + (n<<1) + ch - '0', ch = getchar_unlocked();
			n = n*sign;

			return n;
		}
		inline void inpI2(int &a,int &b){
			a=inpI();
			b=inpI();
		}
		inline void inpI3(int &a,int &b,int &c){
			a=inpI();
			b=inpI();
			c=inpI();
		}

		inline double inpD() {
			double res = 0.0;
			char c;
			while(1) {
				c = getchar();
				// c = getchar_unlocked();
				if(c == ' ' || c == '\n') continue;
				else break;
			}
			res = c - '0';
			while(1) {
				c = getchar();
				// c = getchar_unlocked();
				if(c >= '0' && c <= '9') res = 10 * res + c - '0';
				else break;
			}
			if(c == '.') {
				double decimal = 0.0, divi = 1.0;
				while(1) {
					c = getchar();
					// c = getchar_unlocked();
					if(c >= '0' && c <= '9') decimal += (c - '0') / (divi *= 10.0);
					else break;
				}
				res += decimal;
			}
			return res;
		}

		inline void outpD(double N) {
			char buff[24],sz=0;
			int integer = N;
			int decimal = (N - integer) * 10000000;
			int tmp = decimal;

			while(decimal) {
				buff[sz++] = '0' + decimal % 10;
				decimal /= 10;
			}
			for(int decimal2 = 1000000; decimal2 > tmp; decimal2 /= 10) {
				buff[sz++] = '0';
			}
			buff[sz++] = '.';
			if(integer == 0) buff[sz++] = '0';
			while(integer) {
				buff[sz++] = '0' + integer % 10;
				integer /= 10;
			}
			while(--sz>=0)
				putchar(buff[sz]);
			// putchar_unlocked(buff[sz]);
			putchar(10);
			// putchar_unlocked(10);
		}
		inline int outpULLI(ULLI u){
			return printf("%llu\n",u);
		}
		inline int outpLLI(LLI lli){
			return printf("%lld\n",lli);
		}
		inline void outpI(int a) {
			char c;
			char snum[20];
			int i=0;
			int sign = 0;
			if(a < 0) sign = 1;
			a = abs(a);
			do {
				snum[i++]=a%10+48;
				a=a/10;
			} while(a!=0);
			i=i-1;
			if(sign) 
				putchar('-');
			// putchar_unlocked('-');

			while(i>=0)
				putchar(snum[i--]);
			// putchar_unlocked(snum[i--]);
			putchar('\n');
			// putchar_unlocked('\n');
		}
		inline void outpI2(int a,int b){
			printf("%d ",a);
			outpI(b);
		}
		inline int outpS(char *s){
			return printf("%s\n",s);
		}
		/*  // Giving 'function defined twice' error while running Graph.cpp Code
		void reorderLLI(LLI &x, LLI& y){
		LLI xCopy, yCopy;
		if (x < y){
		y = xCopy;
		x = yCopy;
		}
		}

		void reorderI(int &x, int& y){
		int xCopy, yCopy;
		if (x < y){
		y = xCopy;
		x = yCopy;
		}
		}
		*/
		template<typename T1> void QL_swap(T1 &x, T1 &y){
			/*	Below code is risky
			x = x+y;
			y = x-y;
			x = x-y;
			*/
			T1 tmp;
			tmp=x;
			x=y;
			y=tmp;
		}


		// commented while using Graph class.
#if 0
		void QL_swapChars(char *a,char *b){
			char tmp=*a;
			*a=*b;
			*b=tmp;
		}
#endif

		/*	Note - Lesson Learnt - return type should also be promoted while overloading the operator,
		otherwise buggy code.
		Also, if a & b have return type ULLI and LLI, we'll get ambiguity error. Both types 
		should be unsigned in order to make it unambiguous.
		As if int is promoted to ULLI, both would be promoted or both would not be.
		*/
		/*	NOTE - gcd{a,b} = gcd{|a|, b} = gcd{a,|b|} = gcd{|a|, |b|}
		And gcd(a,0) = a.
		*/
		template<typename T1> T1 gcd(T1 a, T1 b) {
			if (!b)return a;
			return gcd(b, a%b);
		}
		LD euclideanDist(int x1,int y1,int x2,int y2){

			return sqrt( (x1-x2)*(x1-x2)/1. + (y1-y2)*(y1-y2)/1. );
		}
	}
}
#endif  // _QL_PRECOMPILATION_BARE_MINIMUM_HPP_

using namespace QoE_Library::QL_Bare_Minimum;

#define PRINT_TIME 0
#define GEN_TEST_CASES 0
#define MAT_SIZE 1005

/*	Test cases -
input-

output-
*/
int countSetBits(int n){
	unsigned int count = 0;
	while (n){
		n &= (n-1) ;
		count++;
	}
	return count;
}
		template<typename T1> inline T1 twoPow(int p) { return ((T1)1) << p; }

template<typename T1> inline bool checkBit(T1 n, int b) { return ( (n & twoPow<T1>(b))!=0); }

int calc(int m[16][16],int r,int c){
	int cnt=0;
	QL_FOR_DEF(i,r){
		QL_FOR_DEF(j,c){
			if(!m[i][j])continue;
			if(in_bounds(i,j+1,r,c)){
				if(m[i][j+1])++cnt;
			}
			if(in_bounds(i+1,j,r,c)){
				if(m[i+1][j])++cnt;
			}
		}
	}
	return cnt;
}

#if 01
int main(){
#if PRINT_TIME
	clock_t t = clock();
#endif

#if 0
	FILE *fIn = freopen("D:\\DUMP\\input.in", "r", stdin);
	FILE *fOut = freopen("D:\\DUMP\\output.out", "w", stdout);
	FILE *fLog = freopen("D:\\DUMP\\log.log", "w", stderr);
	assert(fIn&&fOut&&fLog);
#endif
	int T=inpI();
	int tc=T;

	int a[MAT_SIZE];
	int m[16][16];
	int p[]={1LL,2LL,4LL,8LL,16LL,32LL,64LL,128LL,256LL,512LL,1024LL,2048LL,4096LL,8192LL,16384LL,32768LL,65536LL,131072LL,262144LL,524288LL,1048576LL,2097152LL,4194304LL};
	while (T--){
		int r = inpI();
		int c = inpI();
		int n = inpI();
		int mi=100000;
		int y=p[r*c];
		QL_FOR_DEF(i,y){
			if(countSetBits(i)!=n)continue;

			QL_FOR_DEF(j,r*c){
				m[j/c][j%c]=checkBit(i,j);
			}
			int x=calc(m,r,c);
			mi=min(mi,x);
		}
		printf("Case #%d: %d\n",tc-T,mi);
	}

#if PRINT_TIME
	t = clock() - t;
	// printf("time = %Ld", (double)t/CLOCKS_PER_SEC);
	cout << "time = " << (double)t/CLOCKS_PER_SEC;
#endif
}
#endif

#endif