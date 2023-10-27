//
// Created by 96454 on 2023/10/7.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN int(1e5 + 10)
#define MAXK int(1e2 + 10)
#define MOD 1000000007
#define LL long long

template <typename T> inline void read(T &x){
    char s; int w = 1; x = 0;
    while (!isdigit(s = getchar())) if (s == '-') w = -1;
    while (isdigit(s)) x = (x << 3) + (x << 1), x += s - '0', s = getchar();
    x *= w;
}
int n, k, f[MAXN][MAXK][2][2], siz[MAXN], ff[MAXK][2][2];
vector <int> ver[MAXN];

inline void add(int u, int v){
    ver[u].push_back(v);
}

inline void dp(int x, int fa = -1){
    siz[x] = f[x][0][0][0] = f[x][1][1][0] = 1;
    for (auto v : ver[x]){
        if (v != fa){
            dp(v, x);
            for (int i = 0; i <= min(k, siz[x]); i++){
                ff[i][0][0] = f[x][i][0][0]; f[x][i][0][0] = 0;
                ff[i][0][1] = f[x][i][0][1]; f[x][i][0][1] = 0;
                ff[i][1][0] = f[x][i][1][0]; f[x][i][1][0] = 0;
                ff[i][1][1] = f[x][i][1][1]; f[x][i][1][1] = 0;
            }
            for (int i = 0; i <= min(siz[x], k); i++){
                for (int j = 0; j <= min(siz[v], k - i); ++j){
                    f[x][i + j][0][0] = ((LL) f[x][i + j][0][0] + 1ll * ff[i][0][0] * f[v][j][0][1]) % MOD;
                    f[x][i + j][1][0] = ((LL) f[x][i + j][1][0] + 1ll * ff[i][1][0] * ((LL)f[v][j][0][0] + (LL)f[v][j][0][1])) % MOD;
                    f[x][i + j][0][1] = ((LL) f[x][i + j][0][1] + 1ll * ff[i][0][1] * ((LL) f[v][j][0][1] + (LL) f[v][j][1][1]) + 1ll * ff[i][0][0] * f[v][j][1][1]) % MOD;
                    f[x][i + j][1][1] = ((LL) f[x][i + j][1][1] + 1ll * ff[i][1][0] * ((LL) f[v][j][1][0] + (LL) f[v][j][1][1]) + 1ll * ff[i][1][1] * ((LL) f[v][j][1][0] + (LL) f[v][j][1][1] + (LL) f[v][j][0][1] + (LL) f[v][j][0][0])) % MOD;
                }
            }
            siz[x] += siz[v];
        }
    }
}
int main(){
    read(n), read(k);
    for (int i = 1, u, v; i < n; i++){
        read(u), read(v);
        add(u, v), add(v, u);
    }
    dp(1);
    printf("%d", (1ll * f[1][k][0][1] + 1ll * f[1][k][1][1]) % MOD);
}