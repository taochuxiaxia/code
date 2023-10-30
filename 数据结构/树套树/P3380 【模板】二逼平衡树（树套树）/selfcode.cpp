/**
 * @Author: lndff
 * @Date: 2023/10/27 09:03:24
 * @LastEditors: lndff
 * @LastEditTime: 2023/10/28 11:27:57
 * Description: 
 * Copyright: Copyright (©)}) 2023 lndff. All rights reserved.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N = 5e4 + 10;
const int M = 1e6;

#define int long long

struct Node{
    int val, id;
};

bool operator <(Node x, Node y){
    return x.val != y.val ? x.val < y.val : x.id < y.id;
}
typedef tree<Node, null_type, less<Node>, rb_tree_tag, tree_order_statistics_node_update> Tree;

int n, m, tot, tim, maxx;
int ls[M], rs[M], a[N];
int temp;
Tree tr[M];
Tree::iterator it;

void build(int& x, int l, int r){
    x = ++tot;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls[x], l, mid), build(rs[x], mid + 1, r);
}

void Insert(int x, int l, int r, int pos, int val){
    tr[x].insert(Node{val, ++tim});
    if (l == r){
        maxx = max(maxx, val);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) Insert(ls[x], l, mid, pos, val);
    else Insert(rs[x], mid + 1, r, pos, val);
}
int gr(int x, int l, int r, int sl, int sr, int val){
    if (l == sl && r == sr) return temp = tr[x].order_of_key(Node{val, tim + 1});
    int mid = (l + r) >> 1;
    if (sr <= mid) return gr(ls[x], l, mid, sl, sr, val);
    if (sl > mid) return gr(rs[x], mid + 1, r, sl, sr, val);
    return gr(ls[x], l, mid, sl, mid, val) + gr(rs[x], mid + 1, r, mid + 1, sr, val);
}

int GR(int x, int l, int r, int sl, int sr, int val){
    if (l == sl && r == sr) return temp = tr[x].order_of_key(Node{val, 0});
    int mid = (l + r) >> 1;
    if (sr <= mid) return GR(ls[x], l, mid, sl, sr, val);
    if (sl > mid) return GR(rs[x], mid + 1, r, sl, sr, val);
    return GR(ls[x], l, mid, sl, mid, val) + GR(rs[x], mid + 1, r, mid + 1, sr, val);
}

int GK(int l, int r, int pos){
    int L = 0, R = maxx + 1, mid, cnt;
    while (L < R){
        mid = (L + R) >> 1;
        cnt = gr(1, 1, n, l, r, mid);
        if (cnt < pos) L = mid + 1;
        else R = mid;
    }
    return L;
}

void modify(int x, int l, int r, int pos, int val){
    it = tr[x].lower_bound(Node{a[pos], 1});
    tr[x].erase(it), tr[x].insert(Node{val, ++tim});
    if (l == r){
        maxx = max(maxx, val);
        a[pos] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls[x], l, mid, pos, val);
    else modify(rs[x], mid + 1, r, pos, val);
}

int GP(int x, int l, int r, int sl, int sr, int val){
    if (l == sl && r == sr){
        it = tr[x].lower_bound(Node{val, 0});--it;
        if (it == tr[x].end()) return -INT_MAX;
        else return it -> val;
    }
    int mid = (l + r) >> 1;
    if (sr <= mid) return GP(ls[x], l, mid, sl, sr, val);
    if (sl > mid) return GP(rs[x], mid + 1, r, sl, sr, val);
    return max(GP(ls[x], l, mid, sl, mid, val), GP(rs[x], mid + 1, r, mid + 1, sr, val));
}

int GN(int x, int l, int r, int sl, int sr, int val){
    if (l == sl && r == sr){
        it = tr[x].upper_bound(Node{val, tim + 1});
        if (it == tr[x].end()) return INT_MAX;
        return it -> val;
    }
    int mid = (l + r) >> 1;
    if (sr <= mid) return GN(ls[x], l, mid, sl, sr, val);
    if (sl > mid) return GN(rs[x], mid + 1, r, sl, sr, val);
    return min(GN(ls[x], l, mid, sl, mid, val), GN(rs[x], mid + 1, r, mid + 1, sr, val));
}
template <typename T> void read(T &x){
    char s;int w = 1;x = 0;
    while (!isdigit(s = getchar())) if (s == '-') w = -1;
    while (isdigit(s)) x = (x << 1) + (x << 3), x += s - '0', s = getchar();
    x *= w;
}

template <typename T> void wr(T x){
    static int st[20];int top = 0;
    do{
        st[++top] = x % 10;x /= 10;
    }while(x);
    while (top) putchar(st[top--] + '0');puts("");
}

signed main(){
    freopen("self.in","r",stdin);
    freopen("self.out","w",stdout);
    cin >> n >> m;
    build(temp, 1, n);
    for (int i = 1; i <= n; i++){
        read(a[i]);
        Insert(1, 1, n, i, a[i]);
    }
    for (int i = 1, opt; i <= m; i++){
        read(opt);
        if (opt == 1){
            int l, r, k;
            read(l), read(r), read(k);
            wr(GR(1, 1, n, l, r, k) + 1);
        }
        else if (opt == 2){
            int l, r, k;
            read(l), read(r), read(k);
            wr(GK(l, r, k));
        }
        else if (opt == 3){
            int pos, k;
            read(pos), read(k);
            modify(1, 1, n, pos, k);
        }
        else if (opt == 4){
            int l, r, k;
            read(l), read(r), read(k);
            wr(GP(1, 1, n, l, r, k));
        }
        else{
            int l, r, k;
            read(l);read(r);read(k);
            wr(GN(1, 1, n, l, r, k));
        }
    }
    cout << 1.00 * clock() / CLOCKS_PER_SEC;
    return 0;
}
