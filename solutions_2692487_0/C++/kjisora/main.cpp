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
using namespace std;
//�萔��Ԃ�
int func(int a,int* mote,int i,int n){
	//cout<<"a="<<a<<"i="<<i<<endl;
	if(a==1){return n;}
	if(i>=n){return 0;}
	int answer=0;
	if(a>mote[i]){//�H�ׂ���
		a+=mote[i];//�z��
		answer+=func(a,mote,i+1,n);
	}else{//�H�ׂ��Ȃ�
		//�������ꍇ�ƁA���ׂď������ꍇ�@�ǂ��炪�ǂ��̂�
		int temp=func(2*a-1,mote,i,n);
		temp++;
		if(temp>n-i){
			return n-i;
		}else{//���ׂď����̂����H�ׂ�ق��������ꍇ
			return temp;
		}
	}
	return answer;
}

int main()
{
	//�V���Ƀt�@�C�����I�[�v�����A�X�g���[���ƌ��т���
	//freopen("test.in", "r", stdin);
	freopen("A-small-attempt1.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	freopen("A-small-attempt1.out", "w", stdout);

	int testcasenum;
	cin >> testcasenum;

	for (int t1 = 1; t1 <= testcasenum; ++t1) {
		printf("Case #%d: ", t1);
		int a,n;
		cin >> a>>n;
		
		int* mote=new int[n];
		for(int i=0;i<n;i++){
			cin>>mote[i];
		}
		
		sort(mote,mote+n);//���������ɕ��ׂ�
		int asn=0;
		asn=func(a,mote,0,n);
		cout<<asn<<endl;
		
	}

	return 0;
}
