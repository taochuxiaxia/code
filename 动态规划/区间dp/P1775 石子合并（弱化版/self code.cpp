//
// Created by 96454 on 2023/10/8.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 310

int N, m[MAXN], f[MAXN][MAXN];
int main(){
    memset(f, 0x3f3f3f3f, sizeof(f));
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        scanf("%d", &m[i]);
        m[i] += m[i - 1];
        f[i][i] = 0;
    }
    for (int k = 2; k <= N; k++){
        for (int l = 1; l + k - 1 <= N; l++){
            int r = l + k - 1;
            for (int mid = l; mid <= r; mid++)
            f[l][r] = min(f[l][r], f[l][mid] + f[mid + 1][r] + m[r] - m[l - 1]);
        }
    }
    printf("%d", f[1][N]);
}