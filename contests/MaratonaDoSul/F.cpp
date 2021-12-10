#include<stdio.h>
#define MAX 112345
using ll = long long;

int N;
ll K;
ll a[MAX], b[MAX];

ll busca(ll ini, ll fim){
    if(ini==fim) return ini;
    ll mid = (ini+fim)/2;

    ll v=0;
    for(int i=0; i<N; i++){
        if (mid >= a[i])
            v+=(mid-a[i])/b[i] + 1;
    }
    if(v<K) return busca(mid+1, fim);
    else return busca(ini, mid);
}

int main(){
    scanf("%d %lld", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%lld %lld", &a[i], &b[i]);
    }

    ll d = busca(1, 2e18+10000);

    printf("%lld\n", d);
    return 0;
}