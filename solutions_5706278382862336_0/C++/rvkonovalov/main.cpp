// Microsoft Visual Studio Express 2013 for Windows Desktop

#include <string>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

template <class T>
class zArray{
	friend class TestzArray;
protected:
	int n;
	T *p;
	void CriticalError(){
		//Application->MessageBox("Range Out","zArray Critical Error");
		cout << "zArray Critical Error: Range Out";
	}
	virtual int RealLen(int i){
		//return 10*((i-1)/10+1);  -> Old release
		if (i == 0)return 0;
		int RL = 1;
		i--;
		for (; i>0; i >>= 1)RL <<= 1;
		return RL;
	}
public:
	zArray(){
		n = 0;
	}
	~zArray(){
		Free();
	}
	int Len(){
		return n;
	}
	void Free(){
		if (n)delete[]p;
		n = 0;
	}
	void SetLen(int new_n){
		if (new_n<0)return;
		if (RealLen(n) == RealLen(new_n) && n != 0 && new_n != 0){
			n = new_n;
			return;
		}
		T *new_p;
		int min = (n<new_n ? n : new_n);
		if (new_n)new_p = new T[RealLen(new_n)];
		for (int i = 0; i<min; i++)new_p[i] = p[i];
		if (n)delete[]p;
		n = new_n;
		p = new_p;
	}

	T & operator [](int i){
		if (i< -n || i >= n){//CriticalError();
			string s = "Range Out:  Array Size = "; s += to_string(n);
			s += "  Call operator [] with value = ";    s += to_string(i);
			//Application->MessageBox(s.c_str(),"zArray Critical Error");
			cout << "zArray Critical Error: " << s;
		}
		if (i >= 0)return p[i];
		else    return p[n - (-i)];
	}
	T & last(){
		if (n == 0)CriticalError();
		return p[n - 1];
	}
	T* GetP(){
		if (!n)return 0;
		return p;
	}

	T& Add(){
		SetLen(n + 1);
		return last();
	}
	void Add(T &t){
		SetLen(n + 1);
		p[n - 1] = t;
	}

	void Delete(int i){
		if (i<0 || i >= n)CriticalError();
		for (int k = i; k<n - 1; k++)p[k] = p[k + 1];
		SetLen(n - 1);
	}
	T& Insert(int i){
		if (i<0 || i>n)CriticalError();
		Add();
		for (int k = n - 1; k>i; k--)p[k] = p[k - 1];
		return p[i];
	}
	void Insert(int i, T &t){
		Insert(i) = t;
	}
	zArray & operator=(const zArray &a){
		if (this == &a)return *this;
		SetLen(a.n);
		for (int i = 0; i<n; i++)p[i] = a.p[i];
		return *this;
	}

	void Sort(){
		T *tmp = new T[n];
		T *m, *m1 = p, *m2 = tmp;
		int i1, i2, j, keylen;

		for (keylen = 1; keylen<2 * n; keylen *= 2){   // exampl: n=5
			for (j = 0; j<n; j += 2 * keylen){
				for (i1 = i2 = 0; i1<keylen && i2<keylen && j + keylen + i2<n;){
					if (m1[j + i1] <= m1[j + keylen + i2]){
						m2[j + i1 + i2] = m1[j + i1];        i1++;
					}
					else{
						m2[j + i1 + i2] = m1[j + keylen + i2]; i2++;
					}
				}
				for (; i1<keylen && j + i1<n; i1++)
					m2[j + i1 + i2] = m1[j + i1];
				for (; i2<keylen && j + keylen + i2<n; i2++)
					m2[j + i1 + i2] = m1[j + keylen + i2];
			}
			m = m1;
			m1 = m2;
			m2 = m;
		}
		delete[]tmp;
	}
	bool CheckSort(){
		int i;
		for (i = 1; i<n; i++)if (p[i - 1]>p[i]){
			//Application->MessageBox("Sort Algorithm Incorrectly",
			//                        "MemArray Critical Error");
			cout << "zArray Critical Error: MemArray Critical Error";
			return false;
		}
		return true;
	}

	int BinSearch(T &value){
		// 1. ���� �������� � ����� ��������� ���,
		// ���������� �����-������ ������� � ����� ������
		// (������� ��� ������� value).
		// 2. ���� ��������� ��������� �� ��������� value,
		// �� ���������� ������� � ���������� �������.
		// 3. Method use only "bool operator <=(const T&)"
		// definition for type T
		if (n == 0)return -1;
		int i, min = 0, max = n - 1;
		while (true){
			if (min == max)return min;
			if (min + 1 == max){
				if (value <= p[min])return min;
				return max;
			}
			i = min + (max - min) / 2;
			if (value <= p[i])max = i;
			else           min = i;
		}
	}
};

typedef zArray <int> zIntArray;
typedef zArray <double> zDoubleArray;
typedef zArray <string> zStringArray;
typedef zArray <char> zCharArray;
typedef zArray <zIntArray> zInt2DArray;
typedef zArray <zDoubleArray> zDouble2DArray;
typedef zArray <zStringArray> zString2DArray;
typedef zArray <zCharArray> zChar2DArray;

class zSimpleFile{
	char Delimeter;
	int lex_line, lex_col, lex_pos;
public:
	zStringArray z;

	zSimpleFile(){
		Delimeter = '\t';
		lex_line = lex_col = lex_pos = -1;
	}

	void SetDelimeter(char d){
		Delimeter = d;
	}

	bool GetFile(string FileName){
		int i, n;
		char buf[10240];
		FILE * f;
		bool is_prev_char_0D = false;
		lex_line = lex_col = lex_pos = -1;

		z.Free();
		z.Add();
		f = fopen(FileName.c_str(), "rb");
		if (f == 0)return false;
		do{
			n = fread(buf, 1, 1024, f);
			for (i = 0; (i < n) && (i < 1024); i++){
				if ((buf[i] == '\x0A') && is_prev_char_0D){
					is_prev_char_0D = false;
					continue;
				}
				if ((buf[i] == '\x0D') || (buf[i] == '\x0A')){
					if (buf[i] == '\x0D')is_prev_char_0D = true;
					z.Add();
					continue;
				}
				z[-1] += buf[i];
			}
		} while (n == 1024);

		fclose(f);
		return true;
	}

	bool SaveFile(string FileName, zStringArray &zz){
		int i;
		string s;
		FILE * f;

		f = fopen(FileName.c_str(), "wb");
		if (f == 0)return false;

		for (i = 0; i < zz.Len(); i++){
			s = zz[i];
			if ((i + 1) < zz.Len())s += "\x0D\x0A";
			fwrite(s.c_str(), 1, s.length(), f);
		}
		fclose(f);
		return true;
	}

	string GetLex(int line, int col){ // line: 0 .. z.Len()-1
		string s;                     // col : 0 ..
		s = "";
		if ((line < 0) || (line >= z.Len()) || (col < 0))return s;
		if ((line != lex_line) || (col != lex_col)){
			lex_col = lex_pos = 0;
			lex_line = line;
		}
		for (; lex_pos < z[line].length(); lex_pos++){
			if (z[line][lex_pos] == Delimeter){
				lex_col++;
				if (lex_col > col){
					lex_pos++;
					break;
				}
			}
			else if (lex_col == col)s += z[line][lex_pos];
		}
		return s;
	}
};

//###################################################################

void main(){
	string f1, f2;
	zSimpleFile f;
	zStringArray res;
	int T, n;

	int ProblemType = 1;
	string ProblemC = "A";
	bool isPractice = false;

	if (ProblemType == 0)f1 = "Example.in";
	if (isPractice){
		if (ProblemType == 1)f1 = ProblemC + "-small-practice.in";
		if (ProblemType == 2)f1 = ProblemC + "-large-practice.in";
	}
	else{
		if (ProblemType == 1)f1 = ProblemC + "-small-attempt0.in";
		if (ProblemType == 2)f1 = ProblemC + "-large.in";
	}
	f2 = f1.substr(0, f1.length() - 2) + "out";

	f.GetFile(f1);
	f.SetDelimeter('/');

	T = stoi(f.z[0]);
	for (n = 0; n < T; n++){
		__int64 p, q, del, st_p, st_q;

		res.Add() = "Case #" + to_string(n + 1) + ": ";
		cout << (n + 1) << endl;

		p = stoll(f.GetLex(n + 1, 0));
		q = stoll(f.GetLex(n + 1, 1));

		while (((p % 2) == 0) && ((q % 2) == 0)){
			p /= 2;
			q /= 2;
		}
		
		del = q;
		while ((del % 2) == 0)del /= 2;
		if ((p % del) != 0){
			res[-1] += "impossible";
			continue;
		}
		p /= del;
		q /= del;

		del = q;
		while ((del % 2) == 0)del /= 2;
		if (del != 1){
			res[-1] += "impossible";
			continue;
		}

		for (st_p = 0; p > 0; st_p++)p /= 2;
		for (st_q = 0; q > 0; st_q++)q /= 2;

		res[-1] += to_string(st_q - st_p);		
	}
	
	f.SaveFile(f2, res);	
	cout << "OK ";
	getchar();
}