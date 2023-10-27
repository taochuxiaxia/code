/**
 * @Author: lndff
 * @Date: 2023/10/27 19:27:18
 * @LastEditors: lndff
 * @LastEditTime: 2023/10/27 19:27:18
 * Description: 
 * Copyright: Copyright (©)}) 2023 lndff. All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k, ans;
signed main(){
    int T;
    scanf("%lld", &T);
    while (T--){
        ans = 0;
        scanf("%lld%lld", &n, &k);
        if (k == 1){
            puts("0");continue;
        }
        if (k == 2) ans++;
        if (k >= 4){
            ++ans;
            if (n - 2 >= 0){
                ans += n - 2;
                ++ans;
                if (n >= 3) ans += n - 3;
            }
        }
        if (k >= 5){
            if (n > 2) ans += 2;
            else if (n > 1) ans += 1;
        }
        printf("%lld\n", ans);
    }
}