#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstdlib>
#include <cctype>
#include <ctime>

using namespace std;

template<class T> inline T sqr(T x) { return x*x; }

typedef long long ll;

#define REP(i,n) for (int i=0;i<(n);i++)

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())
//�R���e�i�̂�
#define CLR(a) memset((a), 0 ,sizeof(a))
//a�̓A�h���X

const double PI = acos(-1.0);
/*
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
*/
// SORT(v); sort(array,array+N);
// vector<int>::iterator ite == find(ALL(v),number); *ite
//#define EACH(ite,c) for(typeof((c).begin()) ite=(c).begin(); ite!=(c).end(); ++ite)
// next_permutation(begin, end) �C�e���[�^�������͈͂̎��̏���𐶐�����

int main() {
	/*�e�X�g�P�[�X�ϐ�*/
	int Test;
	scanf("%d", &Test);
	/*�J��Ԃ����̕ϐ��������Y��ɋC��t����*/
	for (int Ca = 1; Ca <= Test; Ca++){
		int K;//�L�[�{�[�h
		int L;//�^�[�Q�b�g;
		int S;//������
		double alph[26] = {0};
		char tmp;
		char target[101];
		double dp[101] = { 0 };
		int kaburi[99];//�S�ē��������̏ꍇ�ōő�99��

		scanf("%d %d %d%*c", &K, &L, &S,&tmp);

		REP(i, K){
			scanf("%c", &tmp);
			int a = tmp - 'A';
			alph[a]++;
		}
		scanf("%*c", &tmp);

		REP(i, 26) {
			alph[i] = alph[i] / K;
		}

		REP(i, L){
			scanf("%c", &tmp);
			target[i+1] = tmp;
		}

		scanf("%*c", &tmp);

		int index = 0;

		int k1 = L+1;

		for (int i = 2; i <= L; i++){
			for (int j = 0; i + j <= L; j++){
				if (target[j] != target[i + j]) break;
				if (i + j == L){
					k1 = i;
					goto KA;
				}
			}
		}
	KA:

		//������m���E�O���m��
		double kaku = 1;
		REP(i, L){
			int num = target[i + 1] - 'A';
			kaku *= alph[num];
		}
		double hazu = 1 - kaku;

		//��蕶���m��
		double kabu = 1;
		for (int i = k1; i <= L;i++){
			int num = target[i] - 'A';
			kabu *= alph[num];
		}

		//��蕶����
		int mozi = L - k1 + 1;
		//dp���߂܂��傤
		dp[0] = 0;
		for (int i = 1; i <= S; i++){
			//�܂��O�����ꍇ�^�X
			dp[i] += hazu * dp[i - 1];
			
			if (i >= L){
				if (k1 == L + 1){
					if (i - L != 0){ dp[i] += kaku * dp[i - L]; }
					else { dp[i] += kaku; }
				} //���Ȃ��ꍇ
				else{
					for (int kabunum = 0; kabunum * mozi + L <= i; kabunum++){
						if (i - (L + kabunum * mozi) != 0) { dp[i] += kaku * pow(kabu, kabunum) * dp[i - (L + kabunum * mozi)]; }
						else { dp[i] += kaku* pow(kabu, kabunum); }
					}
				}
			}
		}

		int saiaku = S / L;

		double kotae = saiaku - dp[S];

		printf("Case #%d: %.7f\n", Ca, kotae);

	}
	return 0;
}

/* printf("Case #%d:",Ca); */