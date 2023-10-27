/**
 * @Author: lndff
 * @Date: 2023/10/27 11:03:24
 * @LastEditors: lndff
 * @LastEditTime: 2023/10/27 11:03:24
 * Description: 
 * Copyright: Copyright (©)}) 2023 lndff. All rights reserved.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N = 5e4 + 10;

#define LL long long

struct Node{
    int val, id;
};

bool operator <(Node x, Node y){
    return x.val != y.val ? x.val < y.val : x.id < y.id;
}
#define Tree tree<Node, null_type, less<Node>, rb_tree_tag, tree_order_statistics_node_update>

template <typename T> void read(T &x){
    char s;int w = 1;x = 0;
    while (!isdigit(s = getchar())) if (s == '-') w = -1;
    while (isdigit(s)) x = (x << 1) + (x << 3), x += s - '0', s = getchar();
    x *= w;
}


int n, m, a[N];
int main(){
    read(n), read(m);
    for (int i = 1; i <= n; i++){
        read(a[i]);
    }
    for (int i = 1, pos; i <= m; i++){
        if (pos == 1){
            int l, r, k;
            read(l), read(r), read(k);
        }
        else if (pos == 2){
            int l, r, k;
            read(l), read(r), read(k);
        }
        else if (pos == 3){
            int pos, k;
            read(pos), read(k);
        }
        else if (pos == 4){
            int l, r, k;
            read(l), read(r), read(k);
        }
        else{
            int l, r, k;
            read(l);read(r);read(k);
        }
    }
}