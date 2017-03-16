#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

unsigned char map[1000][1000];
int N;

void dump()
{
    printf("\n");
    for(int n = 0;n < N;++n){
        for(int c = 0;c < N;++c){
            printf("%d ",map[n][c]);
        }printf("\n");
    }printf("\n");
}

int solve(int preN, int n, int c)
{
    if(n >= N) return 0;
    if(c >= N) return 0;
    for(int dc = c;dc < N;++dc){
        // �V�K�J����`�F�b�N
        if(dc == n)continue;
        if(preN >= 0 && n > 0){
            if( map[n][dc] ){
                // preN->n->dc �͐ڑ�����Ă���B
                // preN->dc ��Z��������B
                // �ł����łɒZ������Ă�����A
                // diamond �𔭌������Ɖ�������B
                if( map[preN][dc] ){
                    return 1;
                }else{
                    map[preN][dc] = 2;
                }
            }
        }
        // �@�艺���m�F
        if( map[n][dc] == 1 ){
            // �@�艺���Ċm�F
            if( solve(n,dc,0) ){
                // diamond �����������炵���̂ŕԓ�
                return 1;
            }
        }
    }
    return 0;
}

int solve()
{
    for(int n = 0;n < N - 1;++n){
        if( solve(-1,n,0) ){
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int T;
    scanf("%d\n",&T);
    for(int r = 0;r < T;++r){
        printf("Case #%d: ", r+1);
        int ans = 0;

        // a to b �̓����s��ŕ\�����āA
        // ���Ƃ͂��̒���n���ɂȂ��ł�������
        memset(map,0,1000*1000);
        scanf("%d\n",&N);
        //printf("\n%d\n",N);
        for(int n = 0;n < N;++n){
            int PN;
            scanf("%d\n",&PN);
            //printf("%d ",PN);
            for(int c = 0;c < PN;++c){
                int V;
                scanf("%d",&V);
                //printf("%d ",V);
                V -= 1;
                map[n][V] = 1;
            }
            //printf("\n");
        }

        // �O�s�ڂ���[���D��ŒT�����āA
        // �A������V�K�J��
        //dump();
        ans = solve();
        //dump();

        printf("%s\n",ans?"Yes":"No");
    }
    return 0;
}