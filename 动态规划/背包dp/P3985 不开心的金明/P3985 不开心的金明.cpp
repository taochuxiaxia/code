//
// Created by 96454 on 2023/10/6.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

int v[MAXN], p[MAXN], miv, f[10010][MAXN];
int n, w, sum_v, sumv;
int main(){
    miv = 1001010101;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++) scanf("%d%d", &v[i], &p[i]), miv = min(miv, v[i]), sum_v += v[i];sumv = sum_v;
    for (int i = 1; i <= n; i++) v[i] -= miv - 1, sumv -= miv - 1;
    for (int i = 1; i <= n; i++){
        for (int j = sumv; j >= v[i]; j--){
            for (int k = n; k >= 1; k--){
                if (j + k * (miv - 1) <= w) f[j][k] = max(f[j][k], f[j - v[i]][k - 1] + p[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= sumv; i++)
        for (int j = 1; j <= n; j++){
            ans = max(ans, f[i][j]);
        }
    printf("%d", ans);
}