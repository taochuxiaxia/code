//
// Created by 96454 on 2023/10/8.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 114

int f[MAXN][MAXN], m[123], lens;
string s;
inline void pre(){
    for (int i = 1; i <= 9; m[i] = 1, i++);
    for (int i = 10; i <= 99; m[i] = 2, i++);
    m[100] = 3;
    memset(f, 0x3f3f3f3f, sizeof(f));
    lens = s.length();
    for (int i = 1; i <= lens; i++) f[i][i] = 1;
}

inline bool check(int l, int r,  int len){
    for (int i = l; i <= r; i++){
        if (s[i] != s[(i - l) % len + l]) return false;
    }
    return true;
}
int main(){
    cin >> s;
    s = " " + s;
    pre();
    for (int k = 2; k <= lens; k++){
        for (int i = 1; i + k - 1 <= lens; i++){
            int j = i + k - 1;
            for (int l = i; l < j; f[i][j] = min(f[i][j], f[i][l] + f[l + 1][j]), l++);
            for (int len = 1; len < k; len++){
                if (k % len == 0){
                    if (check(i, j, len))
                        f[i][j] = min(f[i][j], f[i][i + len - 1] + 2 + m[k / len]);
                }
            }
        }
    }
    printf("%d", f[1][lens] - 1);
}