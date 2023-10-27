//
// Created by 96454 on 2023/10/8.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

int N, a[MAXN << 1], f[MAXN << 1][MAXN << 1], f_[MAXN << 1][MAXN << 1];
int main(){
    scanf("%d", &N);
    memset(f, 0x3f3f3f3f, sizeof(f));
    for (int i = 1; i <= N; scanf("%d", &a[i]), f[i][i] = f_[i][i] = 0, a[i] += a[i - 1], i++) ;
    for (int i = N + 1; i < N * 2; a[i] = a[i - N] - a[i - N - 1], f[i][i] = f_[i][i] = 0, a[i] += a[i - 1], i++) ;
    for (int k = 2; k <= N; k++){
        for (int i = 1; i + k - 1 <= N * 2 - 1; i++){
            int j = i + k - 1;
            for (int l = i; l <= j; l++){
                f[i][j] = min(f[i][j], f[i][l] + f[l + 1][j] + a[j] - a[i - 1]);
                f_[i][j] = max(f_[i][j], f_[i][l] + f_[l + 1][j] + a[j] - a[i - 1]);
//                cout << f_[i][j]<<" ";
            }
        }
    }
    int ans1 = 0x3f3f3f3f, ans2 = 0;
    for (int i = 1; i <= N; i++){
        ans1 = min(ans1, f[i][i + N - 1]);
        ans2 = max(ans2, f_[i][i + N - 1]);
    }
//    for (int i = 1; i < N * 2; i++) cout << a[i] - a[i - 1] << " ";
    printf("%d\n%d", ans1, ans2 >> 1);
}