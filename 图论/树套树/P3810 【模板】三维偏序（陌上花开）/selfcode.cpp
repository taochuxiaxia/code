/**
 * @Author: lndff
 * @Date: 2023/10/27 08:16:30
 * @LastEditors: lndff
 * @LastEditTime: 2023/10/27 08:16:30
 * Description: 
 * Copyright: Copyright (©)}) 2023 lndff. All rights reserved.
 */
#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & -x)
template <typename T> void read(T &x){
    int w = 1;x = 0;char s;
    while (!isdigit(s = getchar())) if (s == '-') w = -1;
    while (isdigit(s)) x = (x << 1) + (x << 3), x += s - '0', s = getchar();
    x *= w;
}
const int N = 1e6 + 10;
const int K = 2e5;
int n, k, tot, tot_, num;
struct data{
    int a, b, c;
    #define a(x) dat[x].a
    #define b(x) dat[x].b
    #define c(x) dat[x].c
}dat[N];
int hax[N << 2], ans[N], ret[N], bef[550];
struct SGtree{
    int l, r, val;
}tr[N << 2];
bool cmp(data x, data y){
    return x.a < y.a;
}

int query(int l, int r, int pos){
    if (l == r){
        int sum = 0;
        for (int i = 1; i <= num; i++) sum += tr[bef[i]].val;
        return sum;
    }
    int mid = (l + r) >> 1;
    if (mid >= pos){
        for (int i = 1; i <= num; i++) bef[i] = tr[bef[i]].l;
        return query(l, mid, pos);
    }
    int sum = 0;
    for (int i = 1; i <= num; i++){
        sum += tr[tr[bef[i]].l].val;
        bef[i] = tr[bef[i]].r;
    }
    return sum + query(mid + 1, r, pos);
}
int calc(int x, int y){
    num = 0 ;
    int pos = lower_bound(hax + 1, hax + tot + 1, x) - hax;
    for (int i = pos; i; i -= lowbit(i)){
        bef[++num] = ret[i];
    }
    int pos_ = lower_bound(hax + 1, hax +tot + 1, y) - hax;
    return query(1, tot, pos_);
}

int modify(int x, int l, int r, int pos){
    int xx = x;
    if (!xx) xx = ++tot_;
    tr[xx].l = tr[x].l, tr[xx].r = tr[x].r, tr[xx].val = tr[x].val + 1;
    if (l == r) return xx;
    int mid = (l + r) >> 1;
    if (mid >= pos){
        tr[xx].l = modify(tr[x].l, l, mid, pos);
    }
    else{
        tr[xx].r = modify(tr[x].r, mid + 1, r, pos);
    }
    return xx;
}
void add(int x, int y){
    x = lower_bound(hax + 1, hax + tot + 1, x) - hax;
    y = lower_bound(hax + 1, hax + tot + 1, y) - hax;
    for (int i = x; i <= tot; i += lowbit(i)){
        ret[i] = modify(ret[i], 1, tot, y);
    }
}

void solve(){
    int temp = 1;
    for (int i = 1; i <= n;){
        while (dat[temp + 1].a == dat[i].a){
            ++temp;
        }
        for (int p = i; p <= temp; p++){
            add(b(p), c(p));
        }
        while (i <= temp){
            ans[calc(b(i), c(i))]++;
            i++;
        }
    }
}
int main(){
    
    // freopen("self.in","r",stdin);
    // freopen("self.out","w",stdout);
    read(n);read(k);
    for (int i = 1; i <= n; i++){
        read(a(i));read(b(i));read(c(i));
        hax[++tot] = a(i);hax[++tot] = b(i);hax[++tot] = c(i);
    }
    sort(hax + 1, hax + tot + 1);
    tot = unique(hax + 1, hax + tot + 1) - hax - 1;
    sort(dat + 1, dat + n + 1, cmp);
    solve();
    for (int i = 1; i <= n; i++){
        printf("%d\n", ans[i]);
    }
}