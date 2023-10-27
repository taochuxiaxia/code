//
// P5410 【模板】扩展 KMP（Z 函数）
// Created by Lyney's OtherHalf on 2023/9/27 19:49 .
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 20000010
#define LL long long

char a[MAXN], b[MAXN];
vector <LL> z, zab;
inline vector< LL >get_z(char *s){
    int siz = strlen(s);
    vector<LL> z(siz);
    z[0] = siz;
    for (int i = 1, l = 0, r = 0; i < siz; ++i){
        if (i <= r){
            if (z[i - l] < r - i + 1){
                z[i] = z[i - l];
            }
            else{
                z[i] = max(0, r - i + 1);
                while (i + z[i] < siz && s[z[i]] == s[i + z[i]]) z[i]++;
            }
        }
        else{
            z[i] = max(0, r - i + 1);
            while (i + z[i] < siz && s[z[i]] == s[i + z[i]]) z[i]++;
        }
        if (i + z[i] - 1 > r) l = i, r = z[i] + i - 1;
    }
    return z;
}
vector <LL> a_b_z(char *x, char *y){
    int stra = strlen(x), strb = strlen(y);
    vector <LL> ab_z(max(stra, strb));
    int len_same = 0, maxp = 0, l;
    while (len_same <(min(stra, strb)) && x[len_same] == y[len_same]) ++len_same;
    ab_z[0] = len_same;
    for (int i = 1; i < stra; ++i){
        len_same = maxp + ab_z[maxp] - 1;
        l = z[i - maxp];
        if (i + l <= len_same){
            ab_z[i] = l;
        }
        else{
            int j = max(0, len_same - i + 1);
            while (i + j < stra && j < strb && x[i + j] == y[j]) ++j;
            ab_z[i] = j;
            maxp = i;
        }
    }
    return ab_z;
}
int main(){
    scanf("%s", a);
    scanf("%s", b);
    int stra = strlen(a);
    int strb = strlen(b);
    z = get_z(b);
    zab = a_b_z(a, b);
    LL ans1 = 0, ans2 = 0;
    for (int i = 0; i < strb; ++i){
        ans1 ^= (i + 1) * (z[i] + 1);
    }
    for (int i = 0; i < stra; ++i){
        ans2 ^= (i + 1) * (zab[i] + 1);
    }
    printf("%lld\n%lld", ans1, ans2);
}