//
// Created by lndff on 2023/10/10.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 510;

int n, ball[N], f[N][N], block[N], tot_block, ball_num[N];

int main(){
    scanf("%d", &n);
    memset(f, 0x3f3f3f3f, sizeof(f));
    for (int i = 1; i <= n; i++){
        scanf("%d", &ball[i]);
        if (ball[i] != ball[i - 1] || i == 1) block[++tot_block] = ball[i];
        ball_num[tot_block]++;
    }
    memset(f, 0x3f3f3f3f, sizeof(f));
//    for (int i = 0; i < tot_block; i++, ball_num[i] >= 2 ? f[i][i] = 1 : 2);
    for(int i = 1; i <= tot_block; i++)
    {
        f[i][i] = ball_num[i] >= 2 ? 1 : 2;
    }
    for (int k = 2; k <= tot_block; k++){
        for (int i = 1, j = i + k - 1; j <= tot_block; i++, j++){
            if (block[i] == block[j])
                f[i][j] = min(f[i][j], f[i + 1][j - 1] + ((ball_num[i] + ball_num[j]) >= 3 ? 0 : 1));
            for (int mid = i; mid <= j;  mid++){
                f[i][j] = min(f[i][j], f[i][mid] + f[mid + 1][j]);
            }
//            if (block[i] == block[j])
//                for (int mid = i + 1; mid < j; mid++){
//                    if (block[i] == block[mid] && (ball_num[i] + ball_num[mid] <= 2 || ball_num[mid] + ball_num[j] <= 2)){
//                        f[i][j] = min(f[i][j], f[i + 1][mid - 1] + f[mid + 1][j - 1]);
//                    }
//                }
        }
    }
    if (f[1][tot_block] == 3) --f[1][tot_block];
    printf("%d", f[1][tot_block]);
}