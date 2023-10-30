/**
 * @Author: lndff
 * @Date: 2023/10/30 10:27:50
 * @LastEditors: lndff
 * @LastEditTime: 2023/10/30 10:27:50
 * Description: 
 * Copyright: Copyright (©)}) 2023 lndff. All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int f[N][N], n, ans;
string s[N];
string head;
int check[N];

void dfs(int x, int sum){
    // cout << f[4][4];
    ans = max(ans, sum);
    check[x]++;
    for (int i = 1; i <= n; i++){
        if (check[i] < 2 && f[x][i] != 0 && f[x][i] != s[x].length() && f[x][i] != s[i].length()){
            dfs(i, sum - f[x][i] + s[i].length());
        }
    }
    check[x]--;
}
void match(int x, int y){
    for (int i = 0; i <= min(s[x].length(), s[y].length()) - 1; i++){
        if (s[y][i] == s[x][s[x].length() - 1]){
            bool tag = 0;
            for (int j = 1; i - j >= 0; j++){
                if (s[x][s[x].length() - j - 1] != s[y][i - j]){
                    tag = 1;
                    break;
                }
            }
            if (!tag || i == 0){
                f[x][y] = i + 1;
                return;
            }
        }
    }
}
void solve(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            match(i, j);
        }
    }
    for (int i = 1; i <= n; i++){
        if (s[i][0] == head[0]) dfs(i, s[i].length());
    }
    printf("%d", ans);
}
int main(){
    freopen("P1019.in","r",stdin);
    freopen("P1019.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
    }
    cin >> head;
    solve();
}