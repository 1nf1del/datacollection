#include <stdio.h>

typedef int zint;

zint gcd(zint a,zint b) {
    zint r;
    while (b) {
        r=a % b;
        a=b;
        b=r;
    }
    return a;
}

void elf(void) {
    zint p,q,g;
    scanf("%d/%d", &p , &q);
    //printf("p=%d q=%d\n",p,q);
    g=gcd(p,q);
    p/=g;
    q/=g;
    if (q & (q-1)) {
        printf("impossible\n");
        return;
    }
    g=0;
    while (p<q) {
        g++;
        p*=2;
    }
    printf("%d\n",g);
}

int main(int argc, char **argv) {
    int i,tc;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        elf();
    }
    return 0;
}
