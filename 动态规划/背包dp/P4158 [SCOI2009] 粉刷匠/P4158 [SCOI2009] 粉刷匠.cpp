//
// Created by 96454 on 2023/10/6.
//
#include <bits/stdc++.h>
#define MAXN 51
#define MAXM 3000
using namespace std;

int f[MAXN][MAXM], g[MAXN][MAXM][MAXN];
int sum[MAXN][MAXM];
int main(){
    int n, m, t;
    char s;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            while (!isdigit(s = getchar())) ;
            if (s == '1') sum[i][j] = sum[i][j - 1] + 1;
            else sum[i][j] = sum[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= m; k++){
                for (int q = j - 1; q < k; q++){
                    g[i][j][k] = max(g[i][j][k], g[i][j - 1][q] + max(sum[i][k] - sum[i][q],k - q - sum[i][k] + sum[i][q]));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= t; j++){
            for (int k = 0; k <= min(j, m); ++k){
                f[i][j] = max(f[i][j], f[i - 1][j - k] + g[i][k][m]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= t; i++){
        ans = max(ans, f[n][i]);
    }
    printf("%d", ans);
}