//
// Created by 96454 on 2023/10/6.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 30010

int n, m, v[MAXN], p[MAXN], f[MAXN];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &v[i], &p[i]);
    for (int i = 1; i <= m; i++){
        for (int j = n; j >= v[i]; j--){
            f[j] = max(f[j], f[j - v[i]] + v[i] * p[i]);
        }
    }
    printf("%d", f[n]);
}