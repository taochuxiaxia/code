//
// Created by 96454 on 2023/10/6.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 90;
#define int long long

template <typename T> inline void read(T &x){
    int w = 1;char s;x = 0;
    while (!isdigit(s = getchar())) if (s == '-') w = -1;
    while (isdigit(s)) x = (x << 3) + (x << 1), x += s - '0', s = getchar();
    x *= w;
}

int k, n, ans, p;
int f[MAXN + 2], ff[MAXN + 2][MAXN + 2];

inline void pre(){
    f[0] = 1;f[1] = 1;
    for (int i = 1; i <= MAXN; ++i){
        f[i + 1] = f[i] + f[i - 1];
        ff[i][i] = 1;
        for (int j = 1; j <= i; ++j){
            ff[i + 1][j] = ff[i - 1][j] + ff[i][j];
            if (j == i - 1) ff[i + 1][j] --;
        }
    }
    for (int i = 1; i <= MAXN; i++){
        for (int j = 1; j <= MAXN; j++){
            ff[i][j] += ff[i][j - 1];
        }
    }
}
signed main(){
    pre();
    int t;
    read(t);
    while (t--){
        read(k);read(n);
        ans = 0;p = 0;
        for (; f[p + 1] <= k; ++p);
        for (int i = MAXN; i >= 1; i--){
            if (n > f[i]){
                n -= f[i];
                ans += ff[i][p];
            }
            }
        printf("%lld\n", ans);
    }
}